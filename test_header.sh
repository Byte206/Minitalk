#!/bin/bash

if [ -z "$1" ]; then
    echo "❌ Uso: $0 <PID_SERVER>"
    exit 1
fi

PID=$1
CONFIRMED=0

# Handler para recibir confirmación del servidor
confirm_handler() {
    CONFIRMED=1
}

# Configura el handler para SIGUSR1
trap confirm_handler SIGUSR1

send_bit() {
    CONFIRMED=0
    
    if [ $1 -eq 0 ]; then
        kill -SIGUSR1 $PID 2>/dev/null || exit 1
    else
        kill -SIGUSR2 $PID 2>/dev/null || exit 1
    fi
    
    # Espera confirmación (máximo 1 segundo)
    timeout=100  # 100 * 10ms = 1 segundo
    while [ $CONFIRMED -eq 0 ] && [ $timeout -gt 0 ]; do
        sleep 0.01
        timeout=$((timeout - 1))
    done
    
    if [ $CONFIRMED -eq 0 ]; then
        echo "❌ Timeout esperando confirmación del servidor"
        exit 1
    fi
}

send_char() {
    char=$1
    ascii=$(printf "%d" "'$char")
    
    echo "📤 Enviando '$char' (ASCII $ascii)..."
    
    for i in {7..0}; do
        bit=$(( (ascii >> i) & 1 ))
        send_bit $bit
    done
}

echo "🔗 Conectando con servidor PID: $PID"
echo "   (Este proceso debe recibir señales del servidor)"
echo "   Mi PID: $$"

# Primera señal de conexión
echo "📡 Enviando handshake..."
send_bit 0

sleep 0.2

echo "📡 Enviando header (tamaño = 2)..."

# Header: 2 bytes (00000000 00000000 00000000 00000010)
for i in {1..30}; do 
    send_bit 0
done
send_bit 1
send_bit 0

echo "✅ Header enviado"
sleep 0.2

echo "📨 Enviando mensaje: 'Hi'"

# Envía 'H' (72 = 01001000)
send_char 'H'

# Envía 'i' (105 = 01101001)
send_char 'i'

echo "✅ Mensaje enviado!"
echo "🎉 Test completado. Revisa el servidor."
