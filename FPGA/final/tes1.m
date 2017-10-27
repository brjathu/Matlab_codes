imNew=uint8(zeros(128,128));

for (i=1:128)
    for (j=1:128)
        imNew(i,j)= aa(256*(i-1)+j);
    end
    
end

imshow(imNew)

