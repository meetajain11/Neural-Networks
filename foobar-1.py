def demo(area):
    ans = []
    while(area >= 4):
        ar = int(area**0.5)
        ans.append(ar*ar)
        area = area-ar*ar
    while(area > 0):
        ans.append(1)
        area = area-1

    print(ans)
    

demo(15324)