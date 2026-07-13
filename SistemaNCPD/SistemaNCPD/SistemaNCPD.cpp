#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cstdlib>

using namespace std;

/**
 * @brief Limpia el buffer de entrada para evitar errores al leer datos.
 */
void limpiarEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * @brief Lee un numero entero de forma segura.
 * Evita errores si el usuario escribe letras, simbolos o texto.
 * @param mensaje Mensaje que se muestra al usuario.
 * @return Numero entero validado.
 */
int leerEntero(string mensaje) {
    int numero;

    while (true) {
        cout << mensaje;
        cin >> numero;

        if (cin.fail()) {
            limpiarEntrada();
            cout << "\n[ERROR] Solo se permiten numeros. Intente de nuevo.\n\n";
        }
        else {
            limpiarEntrada();
            return numero;
        }
    }
}

/**
 * @brief Pausa el sistema hasta que el usuario presione ENTER.
 */
void pausar() {
    cout << "\nPresiona ENTER para continuar...";
    cin.get();
}

/**
 * @brief Limpia la pantalla de la consola.
 */
void limpiarPantalla() {
    system("cls");
}

/**
 * @brief Muestra un titulo decorado para las secciones del sistema.
 * @param titulo Texto del titulo.
 */
void mostrarTitulo(string titulo) {
    cout << "====================================================" << endl;
    cout << "        " << titulo << endl;
    cout << "====================================================" << endl;
}

/**
 * @brief Clase modelo que representa a un oficial del NCPD.
 */
class Oficial {
private:
    int id;
    string nombre;
    string rango;

public:
    /**
     * @brief Constructor de la clase Oficial.
     * @param id Identificador del oficial.
     * @param nombre Nombre del oficial.
     * @param rango Rango del oficial.
     */
    Oficial(int id, string nombre, string rango) {
        this->id = id;
        this->nombre = nombre;
        this->rango = rango;
    }

    /**
     * @brief Obtiene el ID del oficial.
     * @return ID del oficial.
     */
    int getId() const {
        return id;
    }

    /**
     * @brief Muestra la informacion del oficial.
     */
    void mostrarInformacion() const {
        cout << "----------------------------------------" << endl;
        cout << "ID Oficial : " << id << endl;
        cout << "Nombre     : " << nombre << endl;
        cout << "Rango      : " << rango << endl;
    }
};

/**
 * @brief Clase modelo que representa una patrulla del NCPD.
 */
class Patrulla {
private:
    int id;
    string unidad;
    string distrito;
    bool disponible;

public:
    /**
     * @brief Constructor de la clase Patrulla.
     * @param id Identificador de la patrulla.
     * @param unidad Nombre o clave de la unidad.
     * @param distrito Distrito asignado.
     */
    Patrulla(int id, string unidad, string distrito) {
        this->id = id;
        this->unidad = unidad;
        this->distrito = distrito;
        this->disponible = true;
    }

    /**
     * @brief Obtiene el ID de la patrulla.
     * @return ID de la patrulla.
     */
    int getId() const {
        return id;
    }

    /**
     * @brief Indica si la patrulla esta disponible.
     * @return true si esta disponible, false si esta en servicio.
     */
    bool estaDisponible() const {
        return disponible;
    }

    /**
     * @brief Cambia el estado de disponibilidad de la patrulla.
     * @param estado Nuevo estado de disponibilidad.
     */
    void cambiarDisponibilidad(bool estado) {
        disponible = estado;
    }

    /**
     * @brief Muestra la informacion de la patrulla.
     */
    void mostrarInformacion() const {
        cout << "----------------------------------------" << endl;
        cout << "ID Patrulla : " << id << endl;
        cout << "Unidad      : " << unidad << endl;
        cout << "Distrito    : " << distrito << endl;
        cout << "Estado      : " << (disponible ? "Disponible" : "En servicio") << endl;
    }
};

/**
 * @brief Clase modelo que representa una orden policial.
 */
class OrdenPolicial {
private:
    int id;
    string tipo;
    string descripcion;
    string distrito;
    string estado;
    int idPatrullaAsignada;

public:
    /**
     * @brief Constructor de la clase OrdenPolicial.
     * @param id Identificador de la orden.
     * @param tipo Tipo de emergencia u orden.
     * @param descripcion Descripcion del reporte.
     * @param distrito Distrito donde ocurre la orden.
     */
    OrdenPolicial(int id, string tipo, string descripcion, string distrito) {
        this->id = id;
        this->tipo = tipo;
        this->descripcion = descripcion;
        this->distrito = distrito;
        this->estado = "Pendiente";
        this->idPatrullaAsignada = -1;
    }

    /**
     * @brief Obtiene el ID de la orden.
     * @return ID de la orden.
     */
    int getId() const {
        return id;
    }

    /**
     * @brief Obtiene el estado actual de la orden.
     * @return Estado de la orden.
     */
    string getEstado() const {
        return estado;
    }

    /**
     * @brief Obtiene el ID de la patrulla asignada.
     * @return ID de patrulla asignada o -1 si no tiene.
     */
    int getIdPatrullaAsignada() const {
        return idPatrullaAsignada;
    }

    /**
     * @brief Asigna una patrulla a la orden y cambia su estado.
     * @param idPatrulla ID de la patrulla asignada.
     */
    void asignarPatrulla(int idPatrulla) {
        idPatrullaAsignada = idPatrulla;
        estado = "Asignada";
    }

    /**
     * @brief Marca la orden como completada.
     */
    void completarOrden() {
        estado = "Completada";
    }

    /**
     * @brief Muestra la informacion de la orden policial.
     */
    void mostrarInformacion() const {
        cout << "----------------------------------------" << endl;
        cout << "ID Orden    : " << id << endl;
        cout << "Tipo        : " << tipo << endl;
        cout << "Descripcion : " << descripcion << endl;
        cout << "Distrito    : " << distrito << endl;
        cout << "Estado      : " << estado << endl;

        if (idPatrullaAsignada == -1) {
            cout << "Patrulla    : Ninguna" << endl;
        }
        else {
            cout << "Patrulla    : " << idPatrullaAsignada << endl;
        }
    }
};

/**
 * @brief Funcion generica para mostrar listas de objetos.
 * @tparam T Tipo de objeto que tenga el metodo mostrarInformacion().
 * @param lista Vector de objetos a mostrar.
 */
template <typename T>
void mostrarListaGenerica(const vector<T>& lista) {
    if (lista.empty()) {
        cout << "\nNo hay registros disponibles." << endl;
        return;
    }

    for (const T& elemento : lista) {
        elemento.mostrarInformacion();
    }
}

/**
 * @brief Funcion generica para buscar un objeto por ID.
 * @tparam T Tipo de objeto que tenga el metodo getId().
 * @param lista Vector donde se realiza la busqueda.
 * @param id ID buscado.
 * @return Posicion del objeto encontrado o -1 si no existe.
 */
template <typename T>
int buscarPorId(const vector<T>& lista, int id) {
    for (int i = 0; i < static_cast<int>(lista.size()); i++) {
        if (lista[i].getId() == id) {
            return i;
        }
    }

    return -1;
}

/**
 * @brief Vista del sistema. Se encarga de mostrar informacion al usuario.
 */
class MenuView {
public:
    /**
     * @brief Muestra el encabezado principal del sistema.
     */
    void mostrarLogo() {
        cout << "====================================================" << endl;
        cout << "        NCPD - NIGHT CITY POLICE DEPARTMENT         " << endl;
        cout << "====================================================" << endl;
        cout << "    Sistema de Registro de Patrullas y Ordenes      " << endl;
        cout << "====================================================" << endl;
        cout << "    Estado: ONLINE | Despacho: ACTIVO | Red: OK     " << endl;
        cout << "====================================================" << endl;
    }

    /**
     * @brief Muestra el menu principal.
     */
    void mostrarMenu() {
        cout << "\n[1]  Registrar patrulla" << endl;
        cout << "[2]  Registrar oficial" << endl;
        cout << "[3]  Crear orden policial" << endl;
        cout << "[4]  Asignar orden a patrulla" << endl;
        cout << "[5]  Marcar orden como completada" << endl;
        cout << "[6]  Ver patrullas registradas" << endl;
        cout << "[7]  Ver oficiales registrados" << endl;
        cout << "[8]  Ver ordenes policiales" << endl;
        cout << "[9]  Ver patrullas disponibles" << endl;
        cout << "[10] Ver ordenes pendientes" << endl;
        cout << "[11] Buscar orden por ID" << endl;
        cout << "[12] Salir" << endl;
    }

    /**
     * @brief Muestra un mensaje de exito.
     * @param mensaje Texto del mensaje.
     */
    void mensajeExito(string mensaje) {
        cout << "\n[OK] " << mensaje << endl;
    }

    /**
     * @brief Muestra un mensaje de error.
     * @param mensaje Texto del mensaje.
     */
    void mensajeError(string mensaje) {
        cout << "\n[ERROR] " << mensaje << endl;
    }

    /**
     * @brief Muestra un mensaje de advertencia.
     * @param mensaje Texto del mensaje.
     */
    void mensajeAlerta(string mensaje) {
        cout << "\n[AVISO] " << mensaje << endl;
    }
};

/**
 * @brief Controlador principal del sistema.
 * Conecta la vista con los modelos y administra la logica de negocio.
 */
class SistemaController {
private:
    vector<Patrulla> patrullas;
    vector<Oficial> oficiales;
    vector<OrdenPolicial> ordenes;
    MenuView vista;

public:
    /**
     * @brief Inicia el sistema y controla el menu principal.
     */
    void iniciarSistema() {
        int opcion;

        system("color 0B");

        do {
            limpiarPantalla();
            vista.mostrarLogo();
            vista.mostrarMenu();

            opcion = leerEntero("\nSeleccione una opcion: ");

            switch (opcion) {
            case 1:
                registrarPatrulla();
                break;
            case 2:
                registrarOficial();
                break;
            case 3:
                crearOrden();
                break;
            case 4:
                asignarOrden();
                break;
            case 5:
                completarOrden();
                break;
            case 6:
                verPatrullas();
                break;
            case 7:
                verOficiales();
                break;
            case 8:
                verOrdenes();
                break;
            case 9:
                verPatrullasDisponibles();
                break;
            case 10:
                verOrdenesPendientes();
                break;
            case 11:
                buscarOrden();
                break;
            case 12:
                cout << "\nCerrando terminal NCPD..." << endl;
                break;
            default:
                vista.mensajeError("Opcion no valida.");
                pausar();
                break;
            }

        } while (opcion != 12);
    }

    /**
     * @brief Registra una nueva patrulla.
     */
    void registrarPatrulla() {
        int id;
        string unidad;
        string distrito;

        limpiarPantalla();
        mostrarTitulo("REGISTRO DE PATRULLA NCPD");

        id = leerEntero("ID de patrulla: ");

        if (buscarPorId(patrullas, id) != -1) {
            vista.mensajeError("Ya existe una patrulla con ese ID.");
            pausar();
            return;
        }

        cout << "Nombre de unidad: ";
        getline(cin, unidad);

        cout << "Distrito asignado: ";
        getline(cin, distrito);

        patrullas.push_back(Patrulla(id, unidad, distrito));

        vista.mensajeExito("Patrulla registrada correctamente.");
        pausar();
    }

    /**
     * @brief Registra un nuevo oficial.
     */
    void registrarOficial() {
        int id;
        string nombre;
        string rango;

        limpiarPantalla();
        mostrarTitulo("REGISTRO DE OFICIAL NCPD");

        id = leerEntero("ID de oficial: ");

        if (buscarPorId(oficiales, id) != -1) {
            vista.mensajeError("Ya existe un oficial con ese ID.");
            pausar();
            return;
        }

        cout << "Nombre del oficial: ";
        getline(cin, nombre);

        cout << "Rango: ";
        getline(cin, rango);

        oficiales.push_back(Oficial(id, nombre, rango));

        vista.mensajeExito("Oficial registrado correctamente.");
        pausar();
    }

    /**
     * @brief Crea una nueva orden policial.
     */
    void crearOrden() {
        int id;
        string tipo;
        string descripcion;
        string distrito;

        limpiarPantalla();
        mostrarTitulo("CREAR ORDEN POLICIAL");

        id = leerEntero("ID de orden: ");

        if (buscarPorId(ordenes, id) != -1) {
            vista.mensajeError("Ya existe una orden con ese ID.");
            pausar();
            return;
        }

        cout << "Tipo de orden: ";
        getline(cin, tipo);

        cout << "Descripcion: ";
        getline(cin, descripcion);

        cout << "Distrito: ";
        getline(cin, distrito);

        ordenes.push_back(OrdenPolicial(id, tipo, descripcion, distrito));

        vista.mensajeExito("Orden policial creada correctamente.");
        pausar();
    }

    /**
     * @brief Asigna una orden pendiente a una patrulla disponible.
     */
    void asignarOrden() {
        int idOrden;
        int idPatrulla;

        limpiarPantalla();
        mostrarTitulo("ASIGNAR ORDEN A PATRULLA");

        if (ordenes.empty()) {
            vista.mensajeAlerta("No hay ordenes registradas.");
            pausar();
            return;
        }

        if (patrullas.empty()) {
            vista.mensajeAlerta("No hay patrullas registradas.");
            pausar();
            return;
        }

        bool hayPendientes = false;
        bool hayDisponibles = false;

        cout << "\nOrdenes pendientes:" << endl;

        for (const OrdenPolicial& orden : ordenes) {
            if (orden.getEstado() == "Pendiente") {
                orden.mostrarInformacion();
                hayPendientes = true;
            }
        }

        if (!hayPendientes) {
            vista.mensajeAlerta("No hay ordenes pendientes para asignar.");
            pausar();
            return;
        }

        cout << "\nPatrullas disponibles:" << endl;

        for (const Patrulla& patrulla : patrullas) {
            if (patrulla.estaDisponible()) {
                patrulla.mostrarInformacion();
                hayDisponibles = true;
            }
        }

        if (!hayDisponibles) {
            vista.mensajeAlerta("No hay patrullas disponibles.");
            pausar();
            return;
        }

        idOrden = leerEntero("\nIngrese ID de la orden: ");
        idPatrulla = leerEntero("Ingrese ID de la patrulla: ");

        int posOrden = buscarPorId(ordenes, idOrden);
        int posPatrulla = buscarPorId(patrullas, idPatrulla);

        if (posOrden == -1) {
            vista.mensajeError("No existe una orden con ese ID.");
            pausar();
            return;
        }

        if (posPatrulla == -1) {
            vista.mensajeError("No existe una patrulla con ese ID.");
            pausar();
            return;
        }

        if (ordenes[posOrden].getEstado() != "Pendiente") {
            vista.mensajeError("La orden seleccionada no esta pendiente.");
            pausar();
            return;
        }

        if (!patrullas[posPatrulla].estaDisponible()) {
            vista.mensajeError("La patrulla seleccionada no esta disponible.");
            pausar();
            return;
        }

        ordenes[posOrden].asignarPatrulla(idPatrulla);
        patrullas[posPatrulla].cambiarDisponibilidad(false);

        vista.mensajeExito("Orden asignada correctamente. Patrulla enviada al distrito.");
        pausar();
    }

    /**
     * @brief Marca una orden asignada como completada.
     */
    void completarOrden() {
        int idOrden;

        limpiarPantalla();
        mostrarTitulo("COMPLETAR ORDEN POLICIAL");

        if (ordenes.empty()) {
            vista.mensajeAlerta("No hay ordenes registradas.");
            pausar();
            return;
        }

        cout << "\nOrdenes asignadas:" << endl;

        bool hayAsignadas = false;

        for (const OrdenPolicial& orden : ordenes) {
            if (orden.getEstado() == "Asignada") {
                orden.mostrarInformacion();
                hayAsignadas = true;
            }
        }

        if (!hayAsignadas) {
            vista.mensajeAlerta("No hay ordenes asignadas para completar.");
            pausar();
            return;
        }

        idOrden = leerEntero("\nIngrese ID de la orden: ");

        int posOrden = buscarPorId(ordenes, idOrden);

        if (posOrden == -1) {
            vista.mensajeError("No existe una orden con ese ID.");
            pausar();
            return;
        }

        if (ordenes[posOrden].getEstado() != "Asignada") {
            vista.mensajeError("Solo se pueden completar ordenes asignadas.");
            pausar();
            return;
        }

        int idPatrulla = ordenes[posOrden].getIdPatrullaAsignada();
        int posPatrulla = buscarPorId(patrullas, idPatrulla);

        ordenes[posOrden].completarOrden();

        if (posPatrulla != -1) {
            patrullas[posPatrulla].cambiarDisponibilidad(true);
        }

        vista.mensajeExito("Orden completada. La patrulla vuelve a estar disponible.");
        pausar();
    }

    /**
     * @brief Muestra todas las patrullas registradas.
     */
    void verPatrullas() {
        limpiarPantalla();
        mostrarTitulo("PATRULLAS REGISTRADAS");
        mostrarListaGenerica(patrullas);
        pausar();
    }

    /**
     * @brief Muestra todos los oficiales registrados.
     */
    void verOficiales() {
        limpiarPantalla();
        mostrarTitulo("OFICIALES REGISTRADOS");
        mostrarListaGenerica(oficiales);
        pausar();
    }

    /**
     * @brief Muestra todas las ordenes policiales.
     */
    void verOrdenes() {
        limpiarPantalla();
        mostrarTitulo("ORDENES POLICIALES");
        mostrarListaGenerica(ordenes);
        pausar();
    }

    /**
     * @brief Muestra solo las patrullas disponibles.
     */
    void verPatrullasDisponibles() {
        limpiarPantalla();
        mostrarTitulo("PATRULLAS DISPONIBLES");

        bool encontrado = false;

        for (const Patrulla& patrulla : patrullas) {
            if (patrulla.estaDisponible()) {
                patrulla.mostrarInformacion();
                encontrado = true;
            }
        }

        if (!encontrado) {
            vista.mensajeAlerta("No hay patrullas disponibles en este momento.");
        }

        pausar();
    }

    /**
     * @brief Muestra solo las ordenes pendientes.
     */
    void verOrdenesPendientes() {
        limpiarPantalla();
        mostrarTitulo("ORDENES PENDIENTES");

        bool encontrado = false;

        for (const OrdenPolicial& orden : ordenes) {
            if (orden.getEstado() == "Pendiente") {
                orden.mostrarInformacion();
                encontrado = true;
            }
        }

        if (!encontrado) {
            vista.mensajeAlerta("No hay ordenes pendientes.");
        }

        pausar();
    }

    /**
     * @brief Busca una orden policial por su ID.
     */
    void buscarOrden() {
        int idOrden;

        limpiarPantalla();
        mostrarTitulo("BUSCAR ORDEN POR ID");

        if (ordenes.empty()) {
            vista.mensajeAlerta("No hay ordenes registradas.");
            pausar();
            return;
        }

        idOrden = leerEntero("Ingrese ID de orden: ");

        int posicion = buscarPorId(ordenes, idOrden);

        if (posicion == -1) {
            vista.mensajeError("No se encontro una orden con ese ID.");
        }
        else {
            vista.mensajeExito("Orden encontrada.");
            ordenes[posicion].mostrarInformacion();
        }

        pausar();
    }
};

/**
 * @brief Funcion principal del programa.
 * @return Retorna 0 si el programa finaliza correctamente.
 */
int main() {
    SistemaController sistema;
    sistema.iniciarSistema();

    return 0;
}