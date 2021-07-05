class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) 
    {
        while(sx<tx && sy<ty)
        {
            if(ty>tx)
                ty%=tx;
            else
                tx%=ty;
        }
        
        return (sx == tx && sy <= ty && ( ty - sy ) % sx == 0) || (sy == ty && sx <= tx && ( tx - sx ) % sy == 0);
    }
};



// | (x + y, y)

// (x, y) -> (x, x + y) -> (x, 2x + y) -> (x, 3x + y) <- (x, (3x + y)%x ).

// (1, 3) ->(4, 3) -> (4 , 7) -> (4,11) <- (4,3) <- (1,3)

// (1,3) && (4,3)  sy==ty && sx<=tx &&(tx-sx)%ty ==0 
    
// (3x+y , 3x+2y) -> (nx + my).
// (3x%y , 2y%x).