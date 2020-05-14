% Calcula el VAP más grande en módulo de A y us correspondiente VEP.

function [vap, vep] = MetodoPotencia(A, x, prec)

aux = ones(size(x));

% Iteramos hasta condición de parada.
while norm(x - aux, 1) > prec
    aux = x;
    x = A*aux/norm(A*aux, 2);
end

vep = x;
% Cociente de Rayleigh.
vap = (vep.'*A*vep)/(vep.'*vep);

end
