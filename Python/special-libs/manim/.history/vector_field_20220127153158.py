from manim import *

class Coloring(Scene):
    def construct(self):
        func = lambda pos: pos - LEFT * 5
        colors = [RED, YELLOW, BLUE, DARK_GRAY]
        min_radius = Circle(radius=2, color=colors[0]).shift(LEFT * 5)
        max_radius = Circle(radius=10, color=colors[-1]).shift(LEFT * 5)
        vf = ArrowVectorField(
            func, min_color_scheme_value=2, max_color_scheme_value=10, colors=colors
        )
        self.add(vf, min_radius)
        self.wait()
        vf2 = ArrowVectorField(
            func, min_color_scheme_value=2, max_color_scheme_value=10, colors=colors
        )