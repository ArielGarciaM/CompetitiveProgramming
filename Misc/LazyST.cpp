struct node {
    int l, r; // El nodo representa el intervalo [l, r]
    node *left, *right; // Hijos izquierdos y derechos del nodo.
    int value; // Valor acumulado de la operación en el intervalo [l, r].
    madre lazy; // Esta madre representa las updates pendientes en este nodo.

    int getvalue() {
        // Usa lazy y value para recalcular el valor acumulado en [l, r]
    }

    void compose(madre nuevaActualizacion) {
        // Combina una nueva actualización con las que el nodo ya tenía pendientes
        combinarChidoConLoAnterior(nuevaActualizacion);
    }

    void merge() {
        // Recalcula el valor en un nodo basandose en sus hijos
        value = operacion(left->getvalue(), right->getvalue());
    }

    void push() {
        // Empuja las actualizaciones pendientes a los hijos y recalcula el valor ya actualizado
        left->compose(lazy);
        right->compose(lazy);
        lazy = elValorDefaultQueTengaEstaMamadaQueRepresenteQueNoHayUpdatesPendientes;
        merge();
    }

    node(int l, int r, int* A) : l(l), r(r) {
        if(l == r)
            value = A[l];
        else {
            int m = (l + r)/2;
            left = new node(l, m, A);
            right = new node(m + 1, r, A);
            merge();
        }
    }

    void update(int L, int R, madre valorActualizadoChido) {
        if(R < l || r < L)
            return; // No andes chingando, esta update no es para mi
        if(L <= l && r <= R) {
            compose(valorActualizadoChido); // Yo me encargo de esto carnal, ya no le hables a mis hijos.
            return;
        }
        // No se que pedo, paso la update a mis hijos.
        push(); // Primero mueves lo que estaba pendiente antes
        left->update(L, R, valorActualizadoChido); // Y luego les metes la nueva
        right->update(L, R, valorActualizadoChido);
        merge(); // Ahora recalculas el valor en este nodo.
    }

    int query(int L, int R) {
        if(R < l || r < L)
            return neutro; // Para operaciones sin neutro nomás no visitas este nodo.
        if(L <= l && r <= R)
            return getvalue(); // Nota que aquí NO es value porque value tiene el valor ANTES de las updates pendientes.
        // Intersecta parcialmente, nos movemos a los hijos
        push(); // Primero tenemos que mover todo lo pendiente
        merge(); // No vamos a actualizar nada, entonces podemos recalcular el valor de putazo
        return left->query(L, R) + right->query(L, R);
    }

};