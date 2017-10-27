function result = withinBounds(pos)
    global image
    result = 0;
    if (pos > 1) && (pos < size(image,1)*size(image,2)) 
        result = 1;
    end
end

