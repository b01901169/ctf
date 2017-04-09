import pyqrcode
import png

text = 'Steganography is the practice of concealing a file, message, image, or video within another file, message, image, or video. The word steganography combines the Greek words steganos, meaning "covered, concealed, or protected", and graphein meaning "writing".'
v = 17
big_code = pyqrcode.create(text, error='Q', version=v, mode = 'binary')
big_code.png('code.'+str(v)+'.png', scale=3, module_color=[0, 0, 0, 255], background=[0xff, 0xff, 0xff])

