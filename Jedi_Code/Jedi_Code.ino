/*
  Jedi Logiciel
  Loua Ann et Arthur MICHAUD

  VERSIONS HISTORY

  Version V0.1.0

*/

/*-------------------------------------------------
   DEFINE LANGUAGE c
*/------------------------------------------------ -

/*-------------------------------------------------
   INCLUSION DES BIBLIOTHEQUES
*/------------------------------------------------ -

/*-------------------------------------------------
   DEFINITIONS DE TYPES
*/------------------------------------------------ -

/*-------------------------------------------------
   DECLARATION DES CONSTANTES GLOBALES
*/------------------------------------------------ -

/*-------------------------------------------------
   DECLARATION DES VARIABLES GLOBALES
*/------------------------------------------------ -

// Affectation des broches d'entrée/sortie du micro-controleur
//   Côté 1

//   Côté 2

/*-------------------------------------------------
   DECLARATION DES FONCTIONS PROTOTYPES
*/------------------------------------------------ -

int readIR();           // prototype
void ServoControl();    // prototype
void ServoControlReset(); // prototype

Servo myservo;          // Create servo object

bool toggle = false;    // Used as a one shot
bool TheForce = false;  // Variable to know cloud function used.
bool powerON = true;    // initial start up flag

int pos = 0;            // initial servo position
int IRemitter = D1;     // IR Emiter LED on D1
int IRpin = A0;         // IR Photodiode on pin A0
int ambientIR;          // variable to store the IR coming from the ambient
int obstacleIR;         // variable to store the IR coming from the object
int value[10];          // variable to store the IR values
int distance = 0;       // variable that will tell if there is an obstacle or not
int mainLED = A6;       // control for the main lights
int closed = 20;         // Servo closed angle
int open = 155;         // servo open angle

/*-----------------------------------------------------
   FONCTION SETUP : INITIALISATION DU MICRO CONTROLEUR
*/---------------------------------------------------- -
void setup()
{
  // Initialisation des broches d'entrée/sortie du micro-controleur

  // Autres Initialisations

}

/*-----------------------------------------------------
   FONCTION LOOP : BOUCLE INFINIE
*/---------------------------------------------------- -
void loop()
{

}
