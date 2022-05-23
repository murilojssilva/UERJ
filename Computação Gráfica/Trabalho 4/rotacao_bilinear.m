pkg load image;
br=imread('dog.png');
[a b c]=size(br);
br2 = zeros(a,b,c);
br2=uint8(br2);
theta = -0.78539816339744830961566084581988; % 45 degrees
centerX=153;
centerY=105;
for x=1 : b
   for y=1 : a
       % From screen system to center system
       % Center coordinate system
       cx = x-centerX;
       cy = centerY-y;
       % Rotate
       nx = cx*cos(theta)-cy*sin(theta);
       ny = cx*sin(theta)+cy*cos(theta);
       % Return old system
       cx=nx+centerX;
       cy=centerY-ny;
       % Pick up neighbors coordinates origin and float value of coordinate
       Pox = floor(cx);
       Poy = floor(cy);
       xn = cx-floor(cx);
       yn = cy-floor(cy);
       if (cx>1)
         if (cy>1)
           if (cx<b)
             if (cy<a)
                % Bilinear
                br2(y,x,1) = ceil(br(Poy,Pox,1)*(1-xn)*(1-yn)+br(Poy,Pox+1,1)*xn*(1-yn)+br(Poy+1,Pox,1)*(1-xn)*yn+br(Poy+1,Pox+1,1)*xn*yn);
                br2(y,x,2) = ceil(br(Poy,Pox,2)*(1-xn)*(1-yn)+br(Poy,Pox+1,2)*xn*(1-yn)+br(Poy+1,Pox,2)*(1-xn)*yn+br(Poy+1,Pox+1,2)*xn*yn);
                br2(y,x,3) = ceil(br(Poy,Pox,3)*(1-xn)*(1-yn)+br(Poy,Pox+1,3)*xn*(1-yn)+br(Poy+1,Pox,3)*(1-xn)*yn+br(Poy+1,Pox+1,3)*xn*yn);
              endif
            endif
          endif
       endif
   endfor;
endfor;
figure;
imshow(br2);