clear all;

%% Introductory Statements

fprintf('To Serve and Protect\n\n');

%% Assignment of Variables

numCops = 2000; % The number of police officers
numCrims = 2000; % The number of criminals
numVictims = 2000; % The number of victims

%% Running Simulations

for i = 1:numCops
    
    % Assigning the number of criminals each cop can apprehend
    numArrests = randi([0 numCrims]);
    
    % Calculate the decrease in criminals
    numCrims = numCrims - numArrests;
    
    % Calculate the increase in victims
    numVictims = numVictims + (numCrims-numArrests);
    
    % Calculate the percentage increase in victims
    pctVictims = (numVictims - 2000)/2000*100;
    
    
    % Print the results of each loop
    fprintf('%d police officers have apprehended %d criminals.\nThere are now %d victims, an increase of %.2f%%\n\n', i, numArrests, numVictims, pctVictims);
    
end

%% Closing Statements

fprintf('Simulation complete. 2000 police officers have worked together to serve and protect %d victims.\n', numVictims);