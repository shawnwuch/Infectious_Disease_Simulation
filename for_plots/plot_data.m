% This script plots the outcome of disease simulation using the data
% stored in data.txt
clc; clear; close all;
people_num=200; % the number of people in the population, set according to input data
set(0,'defaultfigurecolor',[1 1 1]);
raw_data = importdata('./data_200ppl_0.4vaccine_effectiveness.txt'); % change the input file name to read different files
data = raw_data.data;
x = data(:,1); % disease Transmission probability
y = data(:,2); % Inoculation fraction
z = data(:,3); % Avg disease run
j = data(:,4); % Avg stable ppl after disrease ends
k = data(:,5); % Avg number of people that have been sick in a disease run
xx = reshape(x, 21, 20);
yy = reshape(y, 21, 20);
zz = reshape(z, 21, 20);
jj = reshape(j, 21, 20);
kk = reshape(k, 21, 20);

figure();
surface( xx, yy, zz );
xlabel('Disease Transmission Probability');
ylabel('Fraction of People Inoculated');
zlabel('Average Disease Run (steps)');
set(gca, 'fontsize', 14);
grid on; 
box on;

figure();
surface( xx, yy, kk./people_num );
xlabel('Disease Transmission Probability');
ylabel('Fraction of People Inoculated');
zlabel('Average Fraction of Population Infected by the Disease');
set(gca, 'fontsize', 14);
grid on; 
box on;

figure();
ax = scatter( xx(kk <= people_num * 0.05), yy(kk <= people_num * 0.05), 'filled' );
set(ax, 'linewidth', 1.2, 'markeredgecolor', 'k');
xlabel('Disease Transmission Probability');
ylabel('Fraction of People Inoculated');
title('Cases where >= 95% of People Never Get Sick')
set(gca, 'fontsize', 14);
grid on; 
box on;
% zlabel('');

figure();
[c, h] = contour(xx,yy,zz, 'k', 'linewidth', 1.2);
title('Average Disease Run (steps)');
clabel(c, h, 'fontsize', 14);
xlabel('Disease Transmission Probability');
ylabel('Fraction of People Inoculated');
set(gca, 'linewidth', 1.2, 'fontsize', 14);
box on;

figure();
[c, h] = contour(xx,yy,kk./people_num, 'k', 'linewidth', 1.2);
title('Average Fraction of Population Infected by the Disease');
clabel(c, h, 'fontsize', 14);
xlabel('Disease Transmission Probability');
ylabel('Fraction of People Inoculated');
set(gca, 'linewidth', 1.2, 'fontsize', 14);
box on;

figure();
[c, h] = contour(xx,yy,kk./people_num, [0:0.025:0.05], 'k', 'linewidth', 1.2);
title('Average Fraction of People Infected by the Disease');
clabel(c, h, 'fontsize', 13);
xlabel('Disease Transmission Probability');
ylabel('Fraction of People Inoculated');
set(gca, 'linewidth', 1.2, 'fontsize', 14);
box on;
