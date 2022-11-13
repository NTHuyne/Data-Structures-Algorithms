def bubblesort(a, n):
    sorted = False
    for i in range (n):
        sorted = True
        for j in range (n-i-1):
            if(a[j]>a[j+1]):
                c=a[j]
                a[j]=a[j+1]
                a[j+1]=c
                sorted = False
            if sorted == True:
                break

def main():
    a=[]
    n = int(input("Nhap so luong phan tu: "))
    for i in range (n):
        a.append(int(input(f"Nhap phan tu thu {i+1}:")))
    bubblesort(a,n)
    print(a)

if __name__ == '__main__':
    main()


