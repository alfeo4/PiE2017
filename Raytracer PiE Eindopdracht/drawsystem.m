clear variables

% Draw an opticalSystem from a components file

[fid,message] = fopen('components.txt','r');
if (fid == -1)
    disp (message)
end
% Load component file
header = textscan(fid, '#%s', 'Delimiter', '\n');
data = textscan(fid, 'Medium %f %f', 'CommentStyle', "Surface", 'Delimiter', '\n');

fclose(fid);

% Save ior, calculate cumulative thickness
thickness = data{1};
refractiveIndex = data{2};
xPositions = cumsum([0 thickness']);

