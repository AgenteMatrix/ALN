% Función que itera los métodos iterativos de Gauss-Seidel, Jacobi y Sobrerelajación.

function [x, iter] = iterar(A,b,B, c, x0, nmax, prec)

% Calculamos la norma inicial de ||b + Ax0||_2.
x = x0(:);
res0 = norm(b - A*x0,2);

% Iteramos el método hasta un máximo de nmax veces.
for iter = 1:nmax
    x = B*x + c;
    res = norm(b -A*x,2)/res0;
    % Condición de parada.
    if res < prec
        return;
    end
end

% Si no ha convergido en nmax iteraciones acabamos.
iter = nmax;
error('Error: no convergencia en %d iteraciones\n', nmax)

end
