%This code is designed to serve and protect public safety using the MATLAB programming language

%%Create a 2d grid with dimensions 1000 x 1000
%Grid will have 0s for non-occupied places and 1s for occupied places
grid = zeros(1000,1000); 

%%Set the grid 5 blocks away from the city at (995, 995) to (1000, 1000) to 1 to indicate it is occupied
grid(995:1000, 995:1000) = 1; 

%%Set the grid 5 blocks away from the river at (1, 1) to (6, 6) to 1 to indicate it is occupied
grid(1:6, 1:6) = 1;

%%Define variables for rows and columns
[r, c] = size(grid);

%%Loop through the grid, and optimize the current location by adding 1s to the grid
for i = 2:r-1
    for j = 2:c-1
        if grid(i,j) == 0
            grid(i-1:i+1, j-1:j+1) = 1;
        end
    end
end

%%Create a wall around the city and the river 
grid(1,:) = 1;
grid(r,:) = 1;
grid(:,1) = 1;
grid(:,c) = 1;

%%Define variables for height and width of the wall
height = 10;
width = 10;

%%Loop through the grid to create a wall around the city and the river
for k = 2:r-1
    for l = 2:c-1
        if grid(k,l) == 0
            grid(k:k+height, l-width:l+width) = 1;
        end
    end
end

%%Set the wall at the city to 1 to indicate it is occupied
grid(r-height+1:r, c-width+1:c) = 1; 

%%Set the wall at the river to 1 to indicate it is occupied
grid(1:height, 1:width) = 1;

%%Create a function to run the optimization algorithm
function optimizedGrid = optimizeGrid (grid)
    optimizedGrid = 0;
    [r, c] = size(grid);
    for i = 2:r-1
        for j = 2:c-1
            if grid(i,j) == 0
                grid(i-1:i+1, j-1:j+1) = 1;
            end
        end
    end
    optimizedGrid = grid;
end

%%Run the optimization algorithm to get the optimized grid
optimizedGrid = optimizeGrid(grid);

%%Create a 2d plot to show the optimized grid
figure
pcolor(optimizedGrid), shading interp; title('Optimized Grid')