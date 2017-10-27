function [x y ct] = LeastCostActiveNode()
    global active nodeCost image
    list = find(active==1);
    [minm cord] = min(nodeCost(logical(active)));
    coord = list(cord);
    x = mod(coord-1,size(image,1)) + 1;
    y = (coord - x)/size(image,1) + 1;
    ct = nodeCost(x,y);
end

