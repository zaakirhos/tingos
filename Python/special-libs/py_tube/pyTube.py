from pytube import YouTube
link = 'https://www.youtube.com/watch?v=yUG2dVET2TY&ab_channel=Geethanjali-CartoonsforKids'
video = YouTube(link)
stream = video.streams.get_highest_resolution()
stream.download()