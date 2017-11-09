clear variables

% Draw an opticalSystem from a components and outrays file

[fid,message] = fopen('components.txt','r');
if (fid == -1)
    disp (message)
end
% Load component file
header = textscan(fid, '#%s', 'Delimiter', '\n');
systemdata = textscan(fid, 'Medium %f %f', 'CommentStyle', "Surface", 'Delimiter', '\n');

fclose(fid);

% Save ior, calculate cumulative thickness
thickness = systemdata{1};
refractiveIndex = systemdata{2};
xPositions = cumsum([0 thickness']);

% Load ray data
raydata = importdata('outrays.txt', ' ', 0); % delimiter space, 0 header lines
plot(xPositions, raydata)

% Find the maximum distance from the optical axis for *any* ray.
systemWidth = 1.1*max(max(abs(raydata))); 

% plot lines at interfaces
for (x = xPositions)
    line([x x], [-systemWidth systemWidth],'Color',[0.2 0.2 0.2]);
end

axis([-0.1*xPositions(end), 1.1*xPositions(end), -1.2*systemWidth, 1.2*systemWidth])