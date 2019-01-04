# Simple program that generates a Mario style pyramid with a gap

h = int(input("Height: "))
  
for i in range(h):

    # print the left half of the pyramid
    for k in range(h-i-1):
        print(" ",end="")
    for j in range(i+1):
        print("#",end="")
        
    # generate the gap
    print(" ",end="")
    
    # print the right half of the pyramid
    for m in range(i+1):
        print("#",end="")
    for n in range(h-i-1):
        print(" ",end="")
    
    # generate an endline
    print()
