% Aproximación por un polinomio por el método de mínimos cuadrados.

function [coefs, norm2Res] = polminquad(x, y, grau, plt)

    fprintf('\n');
    fprintf('<strong>Aproximación polinomial por mínimos cuadrados </strong>\n')
    n = length(x);

    % Establecemos un formato.
    format longE;

    % Ponemos los vectores en columna.
    x = x(:);
    y = y(:);

    % Construimos la matriz de Vandermonde associada a x.
    if n <= grau
        error('Grado del polinomio inválido.')
    else

        % La matriz A para las ecuaciones normales es inicializada.
        A = zeros(n, grau + 1);

        % Generamos una matriz de Vandermonde con los valores de x.
        for i = 1:n
            aux = 1.0;
            for j = grau + 1:-1:1
                A(i, j) = aux;
               aux = aux*x(i);
            end
        end

    end

    % Descomposición A = QR.
    [Q, R] = desQR(A,grau);

    % Comprovación de que Q és ortogonal.
    norma_residu = norm(Q'*Q - eye(grau + 1), inf);
    fprintf("Estimación del error de ||Q^tQ - I||_inf: %g\n", norma_residu)

    % Solución del sistema triangular.
    opts.UT = true;
    coefs = linsolve(R, Q'*y, opts);
    norm2Res = norm(A*coefs - y);
    fprintf("Estimación del error de ||Aa - y||_2: %g\n", norm2Res)
    
    % Quehaceres estéticos.
    fprintf("Coeficientes del polinomio:\n\n")
    fprintf("Coefs = \n\n")
    disp(coefs)

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
