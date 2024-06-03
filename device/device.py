import random
import time
import paho.mqtt.client as mqtt

MQTT_BROKER = ""
MQTT_PORT = 1883
MQTT_TEMPERATURE_TOPIC = "home/sensors/temperature"
MQTT_HUMIDITY_TOPIC = "home/sensors/humidity"
MQTT_LIGHT_TOPIC = "home/sensors/light"

def generate_weather_data():
    temperature = round(random.uniform(20, 25), 2)
    humidity = round(random.uniform(60, 70), 2)  
    light_intensity = round(random.uniform(800, 1000), 2) 

    return temperature, humidity, light_intensity

def publish_weather_data(client):
    temperature, humidity, light_intensity = generate_weather_data()
    client.publish(MQTT_TEMPERATURE_TOPIC, temperature)
    client.publish(MQTT_HUMIDITY_TOPIC, humidity)
    client.publish(MQTT_LIGHT_TOPIC, light_intensity)

    print(f"Published: temperature: {temperature}, humidity: {humidity}, light: {light_intensity}")

def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Connected to MQTT Broker!")
    else:
        print(f"Failed to connect, return code {rc}")



def simulate_weather_station():

    client = mqtt.Client()
    client.on_connect = on_connect
    client.connect(MQTT_BROKER, MQTT_PORT, 60)
    client.loop_start()

    try:
        while True:
            publish_weather_data(client)
            time.sleep(2)
    except KeyboardInterrupt:
        client.loop_stop()
        print("Weather station simulation stopped.")

        
if __name__ == "__main__":
    simulate_weather_station()