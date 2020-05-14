% Resolución de sistemas lineales Ax = b por el método iterativo de Sobrerelajación.

 function [x,rho,res,iter] = overRelaxation(A, b, x0, w, nmax, prec)

% Establecemos un formato.
format longE;
 
% Comprobamos los elementos de la diagonal.
tol=1.0e-10;
D=diag(A);
if min(abs(D))<tol
    warning('Error: valores en la diagonal con val.abs < %e.\n',tol)
end

% Ponemos los vectores en columna.
x0 = x0(:);
b = b(:);

% Calculamos el precondicionador.
P = diag(diag(A))/w + tril(A,-1);

% Calculamos la matriz B y el vector c.
B = P\(P-A);
c = P\b;

% Calculamos rho de B para comprobar la convergencia.
rho = max(abs(eig(B)));
if rho >= 1
    warning('Error: método no convergente, rho >= 1.\n')
end

% Iteramos el método.
[x, iter] = iterar(A, b, B, c, x0, nmax, prec);

% Calculamos el error.
res = norm(A*x - b, 2);

% Quehaceres estéticos.
fprintf("\n<strong>SOBRERELAJACIÓN</strong>\n")
fprintf("Parámetro w: %g\n", w)
fprintf("Radio espectral de B_GS: %g\n", rho)
fprintf("Número de iteraciones: %u\n", iter)
fprintf("Error de la solución: ||Ax-b||_2 = %g\n", res)
fprintf("Solución del sistema:\n\n")
fprintf("x = \n\n")
disp(x)

end
