

def tower(n, source, dest, aux):
    if(n == 1):
        print("Move 1 disc from ", source, "to ", dest)
    else:
        tower(n-1, source, aux, dest)
        print("Move ", n, " disc from ", source, " to ", dest)
        tower(n-1, aux, dest, source)


tower(3, "Source", "Destinatioun", "Auxillary")
