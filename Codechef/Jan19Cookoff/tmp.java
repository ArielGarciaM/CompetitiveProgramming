

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;


class Main {
  public static void main(String[] args) throws IOException {

    VivaanScan sc = new VivaanScan();
    VivaanPrint p = new VivaanPrint();
    
    int t=sc.scanInt();
    while(t-- >0) {
      int n=sc.scanInt();
      
      int[][] arr1=new int[n][n];
      int[][] arr2=new int[n][n];
      
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          arr1[i][j]=sc.scanInt();
        }
      }
      
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          arr2[i][j]=sc.scanInt();
        }
      }
      
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(arr1[i][j]!=arr2[i][j]) {
              foo(arr1,n,j);
            }
        }
      }
      
      boolean res=true;
//      p.println("");
      for (int i = 0; i < n && res; ++i) {
        for (int j = 0; j < n; ++j) {
          if(arr1[i][j]!=arr2[i][j]) {
            res=false;
            break;
          }
//          p.print(arr1[i][j]+" ");
        }
//        p.println("");
      }
      
      
      
      p.println(res?"Yes":"No");
      
    }
    
    p.close();
  }
  
  
  
  public static void foo(int[][] arr,int n,int k) {
    for(int i=0;i<n;i++) {
      int remp=arr[i][k];
      arr[i][k]=arr[k][i];
      arr[k][i]=remp;
    }
  }
  


  static class VivaanScan {
    private byte[] buf = new byte[1024]; // Buffer of Bytes
    private int index;
    private InputStream in;
    private int total;

    public VivaanScan() {
      in = System.in;
    }

    public int scan() throws IOException // Scan method used to scan buf
    {
      if (total < 0)
        throw new InputMismatchException();
      if (index >= total) {
        index = 0;
        total = in.read(buf);
        if (total <= 0)
          return -1;
      }
      return buf[index++];
    }

    public int scanInt() throws IOException {
      int integer = 0;
      int n = scan();
      while (isWhiteSpace(n)) // Removing starting whitespaces
        n = scan();
      int neg = 1;
      if (n == '-') // If Negative Sign encounters
      {
        neg = -1;
        n = scan();
      }
      while (!isWhiteSpace(n)) {
        if (n >= '0' && n <= '9') {
          integer *= 10;
          integer += n - '0';
          n = scan();
        } else
          throw new InputMismatchException();
      }
      return neg * integer;
    }

    public double scanDouble() throws IOException {
      double doub = 0;
      int n = scan();
      while (isWhiteSpace(n))
        n = scan();
      int neg = 1;
      if (n == '-') {
        neg = -1;
        n = scan();
      }
      while (!isWhiteSpace(n) && n != '.') {
        if (n >= '0' && n <= '9') {
          doub *= 10;
          doub += n - '0';
          n = scan();
        } else
          throw new InputMismatchException();
      }
      if (n == '.') {
        n = scan();
        double temp = 1;
        while (!isWhiteSpace(n)) {
          if (n >= '0' && n <= '9') {
            temp /= 10;
            doub += (n - '0') * temp;
            n = scan();
          } else
            throw new InputMismatchException();
        }
      }
      return doub * neg;
    }

    private boolean isWhiteSpace(int n) {
      if (n == ' ' || n == '\n' || n == '\r' || n == '\t' || n == -1)
        return true;
      return false;
    }
  }

  static class VivaanPrint {
    private final BufferedWriter bw;

    public VivaanPrint() {
      this.bw = new BufferedWriter(new OutputStreamWriter(System.out));
    }

    public void print(Object object) throws IOException {
      bw.append("" + object);
    }

    public void println(Object object) throws IOException {
      print(object);
      bw.append("\n");
    }

    public void close() throws IOException {
      bw.close();
    }

    public void flush() throws IOException {
      bw.flush();
    }
  }

}

