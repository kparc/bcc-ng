l[ii]{x>y}
l[ii]{x<y}
/\\
l[i]{r:1;W(r>x){r+:x};r}
l[i]{r:1;W(r<x){r+:x};r}
//l[42]
\\
z[i]{n:0;W(x>1){x:$[x&1;(\x)+x+1;/x];n+:1};n}
\\

f[i]{k:x+42;k:x*(k+1)+(x*k)}
//f[3]
\\
x:4
0-x
a[ii]$[x;a[x-1;$[y;a[x;y-1];1]];1+y]
a[3;4]
\\

//m[i]{k:0;N(x){r:-1.5+2*i%x;N(x){s:-1+2*j%x;p:q:0.;m:50;W(m*4>(t:p*p)+u:q*q){m-:1;q:s+2*p*q;p:r+t-u};k+:0=m}};k}
//\\
//f[i]{k:x+42;k+1+x*k}
//f[i]{k:x+42;k:(k+1)+x*k;x*k}


f[i]{k:x;k+1+x*3}
f[3]
\\

z[i]{n:0;W(x>1){x:$[x&1;(\x)+x+1;/x];n+:1};n}
\\
a[ii]$[x;a[-x;$[y;a[x;-y];1]];+y]
b[Ii]{h:#x;l:0;W(h>l)$[y>x[i:/l+h];l:i+1;h:i];l}
f[iII]{m:0;$[k:-x;W(x){x-:1;j:*y;N(k)y[i]:y[+i];y[k]:j;j:f[k;y;z];$[m<j;m:j;]};{N(#y)z[i]:y[i];W(j:*z){m+:1;N(j){k:z[i];z[i]:z[j];z[j]:k;j-:1}}}];m}
t[ii]$[y;[x;t[-x*2;y];t[x*2;y-:1]];[x;;]]
c[J]$[x[1];(*x)+c[x[1]]-c[x[2]];*x]
m[i]{k:0;N(x){r:-1.5+2*i%x;N(x){s:-1+2*j%x;p:q:0.;m:50;W(m*4>(t:p*p)+u:q*q){m-:1;q:s+2*p*q;p:r+t-u};k+:0=m}};k}
z[i]{n:0;W(x>1){x:$[x&1;(\x)+x+1;/x];n+:1};n}
r[I]{n:#x;h:/#x;c:0;N(h){t:x[i];j:-1+n-i;x[i]:x[j];x[j]:t};x}
\\

f[i]{x}
f[2]
\\

f[ii]{k:x*y;k}
//f[1;1]
\\
/z[i]{n:0;W(x>1){x:$[x&1;(\x)+x+1;/x];n+:1};n}
/18=z[30]
/\\
/r[I]{n:#x;h:/#x;c:0;N(h){t:x[i];j:-1+n-i;x[i]:x[j];x[j]:t};x}
/x:!10
/r[x]
/\\
/\\
/b[Ii]{h:#x;l:0;W(h>l)$[y>x[i:/l+h];l:i+1;h:i];l}
/\\
m[i]{k:0;N(x){r:-1.5+2*i%x;N(x){s:-1+2*j%x;p:q:0.;m:50;W(m*4>(t:p*p)+u:q*q){m-:1;q:s+2*p*q;p:r+t-u};k+:0=m}};k}
m[100]
\\
