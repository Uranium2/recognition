# include <stdlib.h>
# include <stdio.h>

int Haar_feature_1 (int x, int y, int scale, int **M){
    return -M[x,y]+M[x,y+(24*scale)]+2*M[x+(12*scale),y]-2*M[x+(12*scale),y+(24*scale)]-M[x+(24*scale),y]+M[x+(24*scale),y+(24*scale)];
}

int Haar_feature_2 (int x, int y, int scale, int **M){
    return M[x,y]-M[x+(24*scale)]-2*M[x,y+(12*scale)]+2*M[x,y+(12*scale)]-2*M[x,y+(24*scale)]+M[x+(24*scale),y+(24*scale)];
}

int Haar_feature_3 (int x, int y, int scale, int **M){
    return M[x,y]-2*M[x,y+(12*scale)]+M[x,y+(24*scale)]-2*M[x+(12*scale),y]+4*M[x+(12*scale),y+(12*scale)]-2*M[x+(12**scale),y+(24*scale)]+M[x+(24*scale),y+(24*scale)]-2*M[x+(24*scale),y+(12*scale)]+M[x+(24*scale),y];
}

int Haar_feature_4 (int x, int y, int scale, int **M){
    return -M[x,y]+M[x,y+(24*scale)]+2*M[x+(8*scale),y]-2*M[x+(8*scale),y+(24*scale)]-2*M[x+(16*scale),y]+2*M[x+(16*scale),y+(24*scale)]+M[x+(24*scale),y]-M[x+(24*scale),y+(24*scale)];
}

int Haar_feature_5 (int x, int y, int scale, int **M){
    return -M[x,y]+M[x+(24*scale),y]+2*M[x,y+(8*scale)]-2*M[x+(24*scale),y+(8*scale)]-2*M[x,y+(16*scale)]+2*M[x+(24*scale)],y+(16*scale)]+M[x,y+(24*scale)]-M[x+(24*scale),y+(24*scale)];
}

