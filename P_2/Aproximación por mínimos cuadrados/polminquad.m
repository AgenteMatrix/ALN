% Aproximación por un polinomio por el método de mínimos cuadrados.

function [coefs, norm2Res] = polminquad(x, y, grau, plt)

    % Establecemos un formato.
    format longE;

    % Ponemos los vectores en columna.
    x = x(:);
    y = y(:);

    % Construimos la matriz de Vandermonde associada a x.
    if length(x) <= grau
        error('Grado del polinomio inválido.')
    else
        A = vander(x);
    end

    % Descomposición A = QR.
    [Q, R] = desQR(A,grau);

    % Comprovación de que Q és ortogonal.
    norma_residu = norm(transpose(Q)*Q - eye(grau + 1), inf);
    fprintf('\n');
    fprintf("Estimación del error de ||Q^tQ - I||_inf: %g\n", norma_residu)

    % Solución del sistema triangular.
    opts.UT = true;
    coefs = linsolve(R, transpose(Q)*y, opts);
    norm2Res = norm(A*coefs - y);
    fprintf("Estimación del error de ||Aa - y||_2: %g\n", norm2Res)

    % Mostramos un gráfico si plt = 1.
    if (plt == 1)
        Graficar(x, y, coefs)
    end
end

% Descomposición QR por Gram-Schmidt modificado.
function [Q, R] = desQR(A,grau)
    Q = A;
    R = zeros(grau + 1, grau + 1);

    for i = 1:grau + 1
      R(i, i) = norm(Q(:, i), 2);
      Q(:, i) = Q(:, i) / R(i, i);
      for j = i + 1:grau + 1
          R(i, j) = dot(Q(:, i), Q(:, j));
          Q(:, j) = Q(:, j) - R(i, j)*Q(:, i);
      end
    end
end

% Dibujamos los puntos de la tabla y el polinomio.
function Graficar(x, y, coefs)
    xpol = linspace(min(x), max(x), 500);
    ypol = polyval(coefs, xpol);

    hold on
    plot(xpol, ypol, 'r-');
    plot(x, y, 'bo');
    title('Aproximación por mínimos cuadrados')
    xlabel('x')
    ylabel('y')
    legend('polinomio', 'puntos')
    hold off
end
