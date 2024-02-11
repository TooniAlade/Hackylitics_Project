
from transformers import pipeline
import os


classifier = pipeline(task="text-classification", model="SamLowe/roberta-base-go_emotions", top_k=None)

sentences = ["I am having a great day"]

import assemblyai as aai

aai.settings.api_key = "9671698ff465485aacf44dd2d4c81791"
transcriber = aai.Transcriber()

transcript = transcriber.transcribe("record_audio_process/LATEST.wav")
#transcript = transcriber.transcribe("sample1.m4a")

print(transcript.text)

model_outputs = classifier(transcript.text)
max_value_dict = max(model_outputs[0], key=lambda x: x.get('score', 0))
max_value_label = max_value_dict.get('label', None)

print(max_value_label)




