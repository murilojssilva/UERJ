N = 3;
  
     Is = zeros(1, N, 'single');
     x = single([xs; ys]);

     for h = 1:N

         xx = floor(x(:, h));

         ∆ = x(:, h) - xx;
         ∆_m = 1 - ∆;

         F_00 = single(I(xx(1), xx(2)));
         F_01 = single(I(xx(1), xx(2)+1));
         F_10 = single(I(xx(1)+1, xx(2)));
         F_11 = single(I(xx(1)+1, xx(2)+1));

         F_A = F_00*∆ m(1)+F_10*∆(1);
         F_B = F_01*∆ m(1)+F_11*∆(1);

         Is(h) = F_A*∆ m(2)+F_B*∆(2);
