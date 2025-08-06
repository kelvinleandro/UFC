#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum
{
    ABERTA,
    FECHADA,
    EMERGENCIA,
    FECHANDO,
    ABRINDO
} Estado;

typedef enum
{
    CMD_NENHUM,
    CMD_FECHAR,
    CMD_ABRIR,
    CMD_SR_EMERG,
    CMD_SR_EMERG_OFF,
    CMD_SENSOR_FECHADO,
    CMD_SENSOR_ABERTO
} Comando;

void printMenu()
{
    printf("\nComandos:\n");
    printf("0 - Nenhum\n");
    printf("1 - Fechar\n");
    printf("2 - Abrir\n");
    printf("3 - Emergência ON\n");
    printf("4 - Emergência OFF\n");
    printf("5 - Sensor Fechado = 1\n");
    printf("6 - Sensor Aberto  = 1\n");
    printf("Escolha um comando: ");
}

void printEstado(Estado estado)
{
    switch (estado)
    {
    case ABERTA:
        printf("Estado: ABERTA     | Motor = 0\n");
        break;
    case FECHADA:
        printf("Estado: FECHADA    | Motor = 0\n");
        break;
    case FECHANDO:
        printf("Estado: FECHANDO   | Motor = 1\n");
        break;
    case ABRINDO:
        printf("Estado: ABRINDO    | Motor = -1\n");
        break;
    case EMERGENCIA:
        printf("Estado: EMERGENCIA | Motor = 0\n");
        break;
    }
}

int main(void)
{
    Estado estado = ABERTA;
    Comando comando;

    int sensorFechado = 0;
    int sensorAberto = 1;
    int emergenciaAtiva = 0;

    while (1)
    {
        printEstado(estado);
        printMenu();
        scanf("%d", (int *)&comando);

        if (comando == CMD_SR_EMERG)
        {
            emergenciaAtiva = 1;
        }
        else if (comando == CMD_SR_EMERG_OFF)
        {
            emergenciaAtiva = 0;
        }
        else if (comando == CMD_SENSOR_FECHADO)
        {
            sensorFechado = 1;
        }
        else if (comando == CMD_SENSOR_ABERTO)
        {
            sensorAberto = 1;
        }

        switch (estado)
        {
        case ABERTA:
            if (emergenciaAtiva)
            {
                estado = EMERGENCIA;
            }
            else if (comando == CMD_FECHAR)
            {
                sensorAberto = 0;
                estado = FECHANDO;
            }
            break;

        case FECHANDO:
            if (emergenciaAtiva)
            {
                estado = EMERGENCIA;
            }
            else if (sensorFechado)
            {
                estado = FECHADA;
            }
            break;

        case FECHADA:
            if (emergenciaAtiva)
            {
                estado = EMERGENCIA;
            }
            else if (comando == CMD_ABRIR)
            {
                sensorFechado = 0;
                estado = ABRINDO;
            }
            break;

        case ABRINDO:
            if (emergenciaAtiva)
            {
                estado = EMERGENCIA;
            }
            else if (sensorAberto)
            {
                estado = ABERTA;
            }
            break;

        case EMERGENCIA:
            if (!emergenciaAtiva)
            {
                estado = ABRINDO;
            }
            break;
        }

        sleep(2);
        system("clear");
    }

    return 0;
}
