%function Work()
clear
clc
clf
global mat;
mat=[0 0 0 0;0 0 0 0;0 0 0 0;0 0 0 0];
axis equal
axis square
axis off

global length;
length=4;
hold on

%Initialization
for i=1:20
    ranX=fix(4*rand())+1;
    ranY=fix(4*rand())+1;
    mat(ranX,ranY)=2;
end

downdate()
left()
right()
down()

function downdate()
    %global
    global mat
    global length

        for i=1:length
            for j=1:length
                patch([i,i,i+1,i+1],[j,j+1,j+1,j],[0.3,0.6,mod(mat(i,j),48)/48])
                text(i+0.5,j+0.5,int2str(mat(i,j)),'color',[1,1,1],'fontsize',20,'HorizontalAlignment','center');
            end
        end
end

%%%%
%%%%
% left
%%%%
%%%%
function  left()
    leftMove();
    leftAdd();
    leftMove();
    downdate();
end
function leftMove()
    %global
    global mat
    global length

    for i=1:length
        for j=1:length
            if mat(j,i)==0
                for k=j+1:length
                    if mat(k,i)~=0
                        mat(j,i)=mat(k,i);
                        mat(k,i)=0;
                    end
                end
            end
        end
    end
    
end
function leftAdd()
    %global
    global mat
    global length
    
    for i=1:length
        for j=1:length
            if mat(j,i)==0
                continue;
            end
            if j<length
                if mat(j,i)==mat(j+1,i)
                    mat(j,i)=2.*mat(j,i);
                    mat(j+1,i)=0;
                end
            end
        end
    end
end


%%%%
%%%%
% right
%%%%
%%%%
function  right()
    rightMove();
    rightAdd();
    rightMove();
    downdate();
end
function rightMove()
    %global
    global mat
    global length

    for i=length:-1:1
        for j=length:-1:1
            if mat(j,i)==0
                for k=j-1:-1:1
                    if mat(k,i)~=0
                        mat(j,i)=mat(k,i);
                        mat(k,i)=0;
                    end
                end
            end
        end
    end
    
end
function rightAdd()
    %global
    global mat
    global length
    
    for i=1:length
        for j=1:length
            if mat(j,i)==0
                continue;
            end
            if j<length
                if mat(j,i)==mat(j+1,i)
                    mat(j,i)=2.*mat(j,i);
                    mat(j+1,i)=0;
                end
            end
        end
    end
end


%%%%
%%%%
% down
%%%%
%%%%
function  down()
    downMove();
    downAdd();
    downMove();
    downdate();
end
function downMove()
    %global
    global mat
    global length

    for i=1:length
        for j=1:length
            if mat(i,j)==0
                for k=j+1:length
                    if mat(i,k)~=0
                        mat(i,j)=mat(i,k);
                        mat(i,k)=0;
                    end
                end
            end
        end
    end
    
end
function downAdd()
    %global
    global mat
    global length
    
    for i=1:length
        for j=1:length
            if mat(i,j)==0
                continue;
            end
            if j<length
                if mat(i,j)==mat(i,j+1)
                    mat(i,j)=2.*mat(i,j);
                    mat(i,j+1)=0;
                end
            end
        end
    end
end