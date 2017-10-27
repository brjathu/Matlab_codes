freq = 165e6;
wirediameter = 19e-3;
c = 2.99792458e8;
lambda = c/freq;


% d = dipoleFolded;
d.Length = lambda/2;
% d.Width = cylinder2strip(wirediameter/2);
d.Spacing = d.Length/60;


Numdirs = 4;
refLength = 0.5;
dirLength = 0.5*ones(1,Numdirs);
refSpacing = 0.3;
dirSpacing = 0.25*ones(1,Numdirs);
initialdesign = [dirLength refSpacing dirSpacing].*lambda;
yagidesign = yagiUda;
% yagidesign.Exciter = d;
yagidesign.NumDirectors = Numdirs;
yagidesign.ReflectorLength = refLength*lambda;
yagidesign.DirectorLength = dirLength.*lambda;
yagidesign.ReflectorSpacing = refSpacing*lambda;
yagidesign.DirectorSpacing = dirSpacing*lambda;
show(yagidesign)