import random
import time
import paho.mqtt.client as mqtt

MQTT_BROKER = "192.168.31.64"
MQTT_PORT = 1883
MQTT_TEMPERATURE_TOPIC = "home/sensors/temperature"
MQTT_HUMIDITY_TOPIC = "home/sensors/humidity"
MQTT_LIGHT_TOPIC = "home/sensors/light"
CLIENT_ID = "clientId-4lju7VgtdO"

def generate_weather_data():
    temperature = round(random.uniform(20, 25), 2)
    humidity = round(random.uniform(60, 70), 2)  
    light = 800

    return temperature, humidity, light

def publish_weather_data(client):
    temperature, humidity, light = generate_weather_data()
    client.publish(MQTT_TEMPERATURE_TOPIC, str(temperature))
    print(f"Published temperature: {temperature} to topic: {MQTT_TEMPERATURE_TOPIC}")
    client.publish(MQTT_HUMIDITY_TOPIC, str(humidity))
    print(f"Published humidity: {humidity} to topic: {MQTT_HUMIDITY_TOPIC}")
    client.publish(MQTT_LIGHT_TOPIC, str(light))
    print(f"Published light: {light} to topic: {MQTT_LIGHT_TOPIC}")

def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("CONNECTED")
    else:
        print(f"FAILED TO CONNECT {rc}")



def simulate_weather_station():

    client = mqtt.Client(client_id=CLIENT_ID)
    client.on_connect = on_connect
    client.connect(MQTT_BROKER, MQTT_PORT, 60)
    client.loop_start()

    try:
        while True:
            publish_weather_data(client)
            time.sleep(2)
    except KeyboardInterrupt:
        client.loop_stop()

        
if __name__ == "__main__":
    simulate_weather_station()