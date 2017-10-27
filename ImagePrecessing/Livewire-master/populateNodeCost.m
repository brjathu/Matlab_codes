function [] = populateNodeCost(start,dest)
    global image activeNodes nodeCost vert horz diag1 diag2 visited active predecessor dest start
    %place the starting node on the active list and assign its cost to zero
    nodeCost(start) = 0;
    active(start) = 1;
    %keep track of the number of active nodes
    activeNodes = 8;
    while ( activeNodes ~= 0 ) 
        %find the node with the least cost value in the active list
        list = find(active==1);
        [ct cord] = min(nodeCost(logical(active)));
        coord = list(cord);
        %mark as visited
        visited(coord) = 1;
        %terminal conditions
        if ( coord == dest ) break, end
        if ( numel(find(visited~=1))==0 ) break, end
        %remove the current node from the active list
        active(coord) = 0;
        if (coord > 1) && (coord < size(image,1)*size(image,2))
            %the following conditions check if the neighboring nodes can be
            %reached from the current node at a lower cost than the
            %previously calculated cost values and modifies their values
            %accordingly, also updating the "predecessor" array
            l = coord - size(image,1); r = coord + size(image,1);
            lu = l-1; ll = l+1; ru = r-1; rl = r+1; u = coord - 1; d = coord + 1;
            if ct + vert(coord) < nodeCost(u)
                nodeCost(u) = ct + vert(coord);
                predecessor(u) = coord;
                if (visited(u)==0) active(u) = 1; end
            end
            if ct + vert(d) < nodeCost(d)
                nodeCost(d) = ct + vert(d);
                predecessor(d) = coord;
                if (visited(d)==0) active(d) = 1; end
            end
            if ct + horz(coord) < nodeCost(l)
                nodeCost(l) = ct + horz(coord);
                predecessor(l) = coord;
                if (visited(l)==0) active(l) = 1; end
            end
            if ct + horz(r) < nodeCost(r)
                nodeCost(r) = ct + horz(r);
                predecessor(r) = coord;
                if (visited(r)==0) active(r) = 1; end
            end
            if ct + diag1(coord) < nodeCost(ru)
                nodeCost(ru) = ct + diag1(coord);
                predecessor(ru) = coord;
                if (visited(ru)==0) active(ru) = 1; end
            end
            if ct + diag1(ll) < nodeCost(ll)
                nodeCost(ll) = ct + diag1(ll);
                predecessor(ll) = coord;
                if (visited(ll)==0) active(ll) = 1; end
            end
            if ct + diag2(coord) < nodeCost(lu)
                nodeCost(lu) = ct + diag2(coord);
                predecessor(lu) = coord;
                if (visited(lu)==0) active(lu) = 1; end
            end
            if ct + diag2(rl) < nodeCost(rl)
                nodeCost(rl) = ct + diag2(rl);
                predecessor(rl) = coord;
                if (visited(rl)==0) active(rl) = 1; end
            end
            activeNodes = sum(sum(active));
        end
    end
end

