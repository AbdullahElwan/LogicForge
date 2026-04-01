#include iostream
#include string

using namespace std;

char transformer(int value){
    if(value==1)
        return 'T';
    else
        return 'F';
} 

int main() {
    
     ((P∧¬Q) ∨ (R⊕C)) → (P↔C) = ((¬P∨Q)∨(P↔C))∧((R↔C)∨(P↔C))
    
    int p[16]={1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0};
    
    int q[16]={1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0};
    
    int r[16]={1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0};
    
    int c[16]={1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};
    
    
    int nq[16];
    
    for(int i=0; i16; i++){
        nq[i]=!q[i];
    }
    
    int pAndNq[16];
    
    for(int i=0; i16; i++){
        pAndNq[i]=p[i]&&nq[i];
    }
    
    int rExC[16];

    for(int i=0; i16; i++){
        rExC[i]=r[i]^c[i];
    }
    
    int pAndNqOrRExC[16];
    
    for(int i=0; i16; i++){
        pAndNqOrRExC[i]=pAndNq[i]rExC[i];
    }
    
      LEFT SIDE IS DONE
    
    int pBicondC[16];
    
    for(int i=0; i16; i++){
        pBicondC[i]=(p[i] == c[i]);
    }
    
    int result[16];
    
    for(int i=0; i16; i++){
        result[i]=(!pAndNqOrRExC[i])pBicondC[i];
    }
    
    ((¬P∨Q)∨(P↔C))∧((R↔C)∨(P↔C))
    
    int nP[16];
    
    for(int i=0; i16; i++){
        nP[i]=!p[i];
    }
    
    int nPOrQ[16];
    
    for(int i=0; i16; i++){
        nPOrQ[i]=nP[i]q[i];
    }
    
    int pIFFc[16];
    
    for(int i=0; i16; i++){
        pIFFc[i]= (p[i] == c[i]);
    }
    
    int nPOrQOrPIFFc[16];
    
    for(int i=0; i16; i++){
        nPOrQOrPIFFc[i]=nPOrQ[i]pIFFc[i];
    }
    
    int rIFFc[16];
    
    for(int i=0; i16; i++){
         FIX use r[i] == c[i], not p[i] == c[i]
        rIFFc[i]= (r[i] == c[i]);
    }
    
    int rIFFcOrPIFFc[16];
    
    for(int i=0; i16; i++){
        rIFFcOrPIFFc[i]=rIFFc[i]pIFFc[i];
    }
    
    int nPOrQOrPIFFcANdRIFFcOrPIFFc[16];
    
    for(int i=0; i16; i++){
        nPOrQOrPIFFcANdRIFFcOrPIFFc[i]=nPOrQOrPIFFc[i]&&rIFFcOrPIFFc[i];
    }
    
    
     -------- PRINT TRUTH TABLE (FIRST) --------

    cout  +----+----+----+----+-----+--------+--------+----------------------+--------+--------+n;
    cout   P   Q   R   C   ¬Q   P∧¬Q    R⊕C    (P∧¬Q) ∨ (R⊕C)       P↔C    RESULT n;
    cout  +----+----+----+----+-----+--------+--------+----------------------+--------+--------+n;

    for(int i=0; i16; i++){
        cout     transformer(p[i])     
                      transformer(q[i])     
                      transformer(r[i])     
                      transformer(c[i])     
                      transformer(nq[i])        
                      transformer(pAndNq[i])         
                      transformer(rExC[i])                
                      transformer(pAndNqOrRExC[i])                
                      transformer(pBicondC[i])         
                      transformer(result[i]) 
                          n;
    }

    cout  +----+----+----+----+-----+--------+--------+----------------------+--------+--------+n;

     -------- PRINT TRUTH TABLE (SECOND, FIXED) --------
     ((¬P∨Q)∨(P↔C))∧((R↔C)∨(P↔C))

    cout  +----+----+----+----+-----+--------+--------+----------------------+--------+------------+--------+n;
    cout   P   Q   R   C   ¬P   ¬P∨Q    P↔C    (¬P∨Q)∨(P↔C)         R↔C    (R↔C)∨(P↔C)  RESULT n;
    cout  +----+----+----+----+-----+--------+--------+----------------------+--------+------------+--------+n;

    for(int i=0; i16; i++){
        cout     transformer(p[i])     
                      transformer(q[i])     
                      transformer(r[i])     
                      transformer(c[i])     
                      transformer(nP[i])        
                      transformer(nPOrQ[i])         
                      transformer(pIFFc[i])                
                      transformer(nPOrQOrPIFFc[i])                
                      transformer(rIFFc[i])           
                      transformer(rIFFcOrPIFFc[i])           
                      transformer(nPOrQOrPIFFcANdRIFFcOrPIFFc[i]) 
                          n;
    }

    cout  +----+----+----+----+-----+--------+--------+----------------------+--------+------------+--------+n;

    return 0;
}