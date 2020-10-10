class Cell:
    def __init__(self,x=0,y=0,dist=0):
        self.x = x
        self.y = y
        self.dist = dist

def is_inside(x,y):
    if((x >= 0 and x < 8) and(y >= 0 and y < 8)):
        return True
    return False

def min_steps(x1, y1, x2, y2):
    stepsX = [2,2,-2,-2,1,1,-1,-1]
    stepsY = [1,-1,1,-1,2,-2,2,-2] 

    queue = []
    queue.append(Cell(x1, y1, 0))
    visited = [[False for i in range(8)] for j in range(8)]

    visited[x1][y1] = True

    while(len(queue) > 0):
        t = queue[0]
        queue.pop(0)

        if(t.x == x2 and t.y == y2):
            return t.dist

        for i in range(0,8):
            x = t.x + stepsX[i]
            y = t.y + stepsY[i]

            if(is_inside(x, y) and not visited[x][y]):
                visited[x][y] = True
                queue.append(Cell(x, y, t.dist+1))

def demo(src,dest):
    x1 = int(src/8)
    y1 = int(src%8)
    x2 = int(dest/8)
    y2 = int(dest%8)
    print(x1,y1,x2,y2)
    print(min_steps(x1,y1,x2,y2)) 

demo(0,1)
