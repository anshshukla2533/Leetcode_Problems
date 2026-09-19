class Solution {
public:
    bool checkOverlap(int r, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xi = 0, yi = 0;
        
        if (xCenter > x2) xi = x2;
        else if (xCenter < x1) xi = x1;
        else xi = xCenter;
        
        if (yCenter > y2) yi = y2;
        else if (yCenter < y1) yi = y1;
        else yi = yCenter;
        
        int distX = xCenter - xi;
        int distY = yCenter - yi;
        
        return (distX * distX + distY * distY) <= (r * r);
    }
};