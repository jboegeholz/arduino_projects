import tkinter as tk
import serial
import serial.tools.list_ports

# Serielle Verbindung (Port ggf. anpassen)
def find_arduino_port():
    ports = serial.tools.list_ports.comports()
    for port in ports:
        if "Arduino" in port.description or "ttyUSB" in port.device:
            return port.device
    return None

port = find_arduino_port()
if port is None:
    raise Exception("Kein Arduino gefunden!")

ser = serial.Serial(port, 9600, timeout=1)

# Steuerzustand
motor_running = False
motor_direction = 1  # 1 = vorwärts, -1 = rückwärts

# PWM senden
def send_pwm(value):
    if motor_running:
        pwm_val = int(value) * motor_direction
        ser.write(f"PWM:{pwm_val}\n".encode('utf-8'))

# Start/Stop
def toggle_motor():
    global motor_running
    motor_running = not motor_running
    if motor_running:
        status_label.config(text="Motor: AN")
        send_pwm(slider.get())
    else:
        status_label.config(text="Motor: AUS")
        ser.write(b"STOP\n")

# Richtungswechsel
def change_direction():
    global motor_direction
    motor_direction *= -1
    dir_label.config(text=f"Richtung: {'Vorwärts' if motor_direction == 1 else 'Rückwärts'}")
    if motor_running:
        send_pwm(slider.get())

if __name__ == '__main__':
    root = tk.Tk()
    root.title("Motorsteuerung via Arduino")

    slider = tk.Scale(root, from_=0, to=255, orient=tk.HORIZONTAL, label="PWM-Wert", command=send_pwm)
    slider.pack(padx=20, pady=10)

    start_button = tk.Button(root, text="Start/Stop", command=toggle_motor)
    start_button.pack(pady=5)

    direction_button = tk.Button(root, text="Richtung wechseln", command=change_direction)
    direction_button.pack(pady=5)

    status_label = tk.Label(root, text="Motor: AUS")
    status_label.pack(pady=5)

    dir_label = tk.Label(root, text="Richtung: Vorwärts")
    dir_label.pack(pady=5)

    root.mainloop()

    # Serielle Verbindung schließen beim Beenden
    ser.close()
