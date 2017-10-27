function [] = pqAdd(x,y)
    global visited active
    if (withinBounds(x,y)==1) && (visited(x,y)==0)
        active(x,y) = 1;
    end
end

