import datetime
import wikipedia
import os
import smtplib
import webbrowser
import cv2 
import pyttsx3
import speech_recognition as sr
import random
import face_recognition as fr
import numpy as np


video_capture = cv2.VideoCapture(0)
adarsh_image = fr.load_image_file("adarsh.jpg")
adarsh_face_encoding = fr.face_encodings(adarsh_image)[0]

known_face_encodings = [
    adarsh_face_encoding
]
known_face_names = [
    "adarsh"
]

# Initialize some variables
face_locations = []
face_encodings = []
face_names = []
process_this_frame = True



video_capture = cv2.VideoCapture(0)
engine = pyttsx3.init('sapi5')

voices = engine.getProperty('voices')
engine.setProperty('voice', voices[0].id)

def speak(audio):
    engine.setProperty('rate', 180) 
    engine.say(audio)
    engine.runAndWait()


def wishMe():
        hour = int(datetime.datetime.now().hour)
        if hour >=0 and hour <12:
            speak("good morning sir...")
        elif hour >= 12 and hour < 18:
            speak("good afternoon sir...")
        else:
            speak("good night sir...")

        speak(" MY NAME his jarvis how may i help you")


def takeCommand():

     r = sr.Recognizer()
     with sr.Microphone() as sources:
        print("listening..")
        audio = r.listen(sources)

     try:
        print("recognizing...")
        query = r.recognize_google(audio)
        print(query)


     except Exception as e:
        print("say that again please..")
        return "None"
     return query

def sendEmail(to,content):
 server = smtplib.SMTP(host='smtp.gmail.com',port=587)
 server.ehlo()
 server.starttls()
 server.login('anantvikrams30@gmail.com','18239383@anant')
 server.sendmail('anantvikrams30@gmail.com',to,content)
 server.close()

if __name__ == '__main__':
    wishMe()
    while True:
        query = takeCommand().lower()
        if 'wikipedia' in query:
            speak('wait for a second i am searching here')
            query = query.replace("wikipedia", "")
            results = wikipedia.summary(query, sentences=3)
            speak("according to google")

            print(results)
            speak(results)

        elif 'tell me about yourself' in query:
          r="my name is jarvis i am a artificial intelligence program i can do lots of works like playing music sending mails searching google wikipedia and utube"
          speak(r)

        elif 'youtube' in query:
         webbrowser.open("youtube.com")

        elif 'google' in query:
         webbrowser.open("google.com")

        elif 'amazon' in query:
         webbrowser.open("amazon.com")

        elif 'music' in query:
            music_dir = 'C:\\Users\ADARSH SINGH\\Music\\favorite'
            songs = os.listdir(music_dir)
            os.startfile(os.path.join(music_dir, random.choice(songs)))

        elif 'the time' in query:
            D = datetime.datetime.now().strftime("%H:%M:%S")
            speak("sir..., THE TIME IS")
            print(D)
            speak(D)

        elif 'date' in query:
            L = datetime.datetime.now().strftime("%d-%m-%y")
            speak("sir..., THE  TODAY date IS")
            print(L)
            speak(L)

        elif 'talented' in query:
            jhagra="thank you sir this comes out only because of your hard work"
            speak(jhagra)

        elif 'prime minister of india' in query:
            rty="shri narendra damodar das modi is the present prime minister of india"
            speak(rty)

        elif 'send email' in query:
            try:
                speak("what should i say?")
                content = takeCommand()
                to = "adarshstriker1@gmail.com"
                sendEmail(to,content)
                speak("email has been sent!")
            except Exception as e:
                print(e)
                speak("sorry my friend anant i am not able to send this email")

        elif 'stop' in query:
            speak("request is completed")
            break

        elif 'identify' in query:

            while True:
                # Grab a single frame of video
                ret, frame = video_capture.read()

                # Resize frame of video to 1/4 size for faster face recognition processing
                small_frame = cv2.resize(frame, (0, 0), fx=0.25, fy=0.25)

                # Convert the image from BGR color (which OpenCV uses) to RGB color (which face_recognition uses)
                rgb_small_frame = small_frame[:, :, ::-1]

                      # Only process every other frame of video to save time
                if process_this_frame:
                    # Find all the faces and face encodings in the current frame of video
                    face_locations = fr.face_locations(rgb_small_frame)
                    face_encodings = fr.face_encodings(rgb_small_frame, face_locations)

                    face_names = []
                    for face_encoding in face_encodings:
                            # See if the face is a match for the known face(s)
                        matches = fr.compare_faces(known_face_encodings, face_encoding)
                        name = "Unknown"

                        # # If a match was found in known_face_encodings, just use the first one.
                            # if True in matches:
                             # first_match_index = matches.index(True)
                             # name = known_face_names[first_match_index]

                          # Or instead, use the known face with the smallest distance to the new face
                        face_distances = fr.face_distance(known_face_encodings, face_encoding)
                        best_match_index = np.argmin(face_distances)
                        if matches[best_match_index]:
                            name = known_face_names[best_match_index]

                        face_names.append(name)

                process_this_frame = not process_this_frame


                                  # Display the results
                for (top, right, bottom, left), name in zip(face_locations, face_names):
                                  # Scale back up face locations since the frame we detected in was scaled to 1/4 size
                    top *= 4
                    right *= 4
                    bottom *= 4
                    left *= 4

                          # Draw a box around the face
                    cv2.rectangle(frame, (left, top), (right, bottom), (0, 0, 255), 2)

                               # Draw a label with a name below the face
                    cv2.rectangle(frame, (left, bottom - 35), (right, bottom), (0, 0, 255), cv2.FILLED)
                    font = cv2.FONT_HERSHEY_DUPLEX
                    cv2.putText(frame, name, (left + 6, bottom - 6), font, 1.0, (255, 255, 255), 1)

                               # Display the resulting image
                cv2.imshow('face recognizer', frame)

                                            # Hit 'q' on the keyboard to quit!
                if cv2.waitKey(1) & 0xFF == ord('q'):
                    break

            video_capture.release()
            cv2.destroyAllWindows()




