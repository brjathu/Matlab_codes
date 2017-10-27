close all
clear all
global image nodeCost visited active predecessor dest start 
imageorg = imread('cameraman.tif');
figure
imshow(imageorg) 
image = im2double(imageorg);
%the visited array will keep track of the visited nodes
visited = zeros(size(image));
%the nodes that are currently in the active list
active = logical(zeros(size(image)));
%the cost of each node from the starting node
nodeCost = double(ones(size(image)));
nodeCost = nodeCost*1000;
%this array will consist of the final node which is on the optimal path from 
%the starting node to the destination 
predecessor = zeros(size(image));
populateBranchCost();
[c r p] = impixel
%obtain the starting and destination positions from mouse clicks
startx = c(1); starty = r(1); start = (starty-1)*size(image,1)+startx;
destX = c(2); destY = r(2); dest = (destY-1)*size(image,1)+destX;
populateNodeCost(start,dest);
disp('Cost population done!');
hold on
vect = 0;
%plot the optimal path
plot(startx,starty,'*');
while (dest ~= start)
    dest = predecessor(dest);
    destX = mod(dest-1,size(image,1)) + 1;
    destY = (dest - destX)/size(image,1) + 1;
    plot(destX,destY,'*');
end
