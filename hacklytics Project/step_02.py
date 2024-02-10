from taipy.gui import Gui

text = "Original text"

page = """
# Getting started with Taipy GUI

My text here: <|{text}|>

<|{text}|input|>
"""

Gui(page).run()