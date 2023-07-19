% Script Name: To Serve and Protect
%% Section 1: Preparation
% Clear the workspace, set preferences, and open data files
clear     % Clear workspace variables
close all % Close all open figures
clc       % Clear command window

warning('off', 'all'); % Supress warnings 

% Set preferences 
set(0,'ShowHidden','on');    % Display Hidden objects 
set(0,'DefaultAxesFontSize', 10);  % Set font size for axes

% Load data 
load('policeData.mat')   % Load police records
load('crimeData.mat')    % Load crime records

%% Section 2: Data Analysis
% Calculate the amount of crime in the area

% Get list of unique crime codes 
crimeCodes = unique(crimeData(:,1));

% Create variables to store crime count and rate information 
totalCrime = 0;  % Total crime count
    
% Count the occurence of each crime 
for i = 1:length(crimeCodes)
    codeIndex = crimeData(:,1) == crimeCodes(i);
    crimeCount = sum(codeIndex);
    totalCrime = totalCrime + crimeCount;
end

% Store total crime count and crime rate per 1,000 people
totalCrimeCount = totalCrime;
crimeRatePer1000 = totalCrime/(sum(policeData(:,2))/1000);

% Display results 
fprintf('Total crime count: %d\n', totalCrimeCount)
fprintf('Crime per 1,000 people: %.2f\n', crimeRatePer1000)

%% Section 3: Plotting and Visualization
% Plot the amount of crime for each month 

% Get unique months 
months = unique(crimeData(:,3));

% Create array to store crime count for each month 
monthlyCrime = [];

% Loop through each month and sum the occurences
% of each crime 
for i = 1:length(months)
    monthIndex = crimeData(:,3) == months(i);  % Get index of current month 
    monthCount = sum(monthIndex);              % Total crime count 
    monthlyCrime = [monthlyCrime; monthCount]; % Store result 
end

% Create bar graph 
figure;
bar(months, monthlyCrime) 

% Set plot properties 
xlabel('Month')
ylabel('Number of Crimes')
title('Crimes by Month')
grid on 


%% Section 4: Prediction and Forecasting 
% Use a moving average model to predict crime rate for next month

% Create moving average model
windowSize = 3;  % Set the window size 
weights = ones(1,windowSize)/windowSize;
mAvgModel = filter(weights, 1, monthlyCrime); 

% Get predictions
nextMonthPrediction = mAvgModel(end);

% Display results
fprintf('Predicted crime rate for next month: %.2f\n', nextMonthPrediction)

%% Section 5: Summary 
% Based on the data, there is a total of %d crimes in the area and
% a crime rate of %.2f per thousand people. Using a 3 month moving 
% average model, the predicted crime rate for the next month is 
% %.2f. 

fprintf('Based on the data, there is a total of %d crimes in the area and \na crime rate of %.2f per thousand people. Using a 3 month moving \naverage model, the predicted crime rate for the next month is \n%.2f. \n',totalCrimeCount, crimeRatePer1000, nextMonthPrediction)