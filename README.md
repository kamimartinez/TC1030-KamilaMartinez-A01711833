# TC1030-KamilaMartinez-A01711833
Trata sobre un paciente y las citas medicas que puede tener. Cada cita tiene componentes de factura y  agregacion de medicos. El paciente puede tener diferentes citas. Existe una herencia entre Doctor y subespecialididades, como Cardiologia y Pediatria. 

### Funcionalidad
Este proyecto permite tener un control sobre las citas del paciente y poder calcular el monto a cobrar por cada cita, dependiendo de la cantidad y tipo de medicos solicitados. 

### Dificultades al momento de desarrollar el proyecto
El manejo de punteros para poder realizar un polimorfismo adecuado fue la mayor dificultad experimentada. Sin embargo, despues de una larga investigación y estudio de estos se puede concluir que se supero esta dificultad.

### Consideraciones
El proyecto esta hecho en c++ standard y corre en todos los sistemas operativos. WINDOWS: 
Compilar con : _g++ main.cpp -o main_
Correr con : main

### Casos que harian que el proyecto deje de funcionar
Debido al tipo de variables que estamos trabajando, como int, long long y string, un mal input de cualquiera de estas haria que el proyeto no funcionara de la manera que se esperaria. Un mal manejo de punteros tambien ocasionaria que el proyecto deje de funcionar. Inclusive en el proceso de creacion del proyecto, un mal manejo de estos impidio que el proyecto fluyero con mayor rapidez.

