#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform float screen_ratio;
uniform vec2 screen_size;
uniform vec2 center;
uniform float zoom;
uniform int itr;
uniform int pwr;
uniform sampler2D name;
uniform int mode;

vec4 map_to_color(float t)
{
   float r = 9.0f * (1.0f - t) * t * t * t;
   float g = 15.0f * (1.0f - t) * (1.0f - t) * t * t;
   float b = 8.5f * (1.0f - t) * (1.0f - t) * (1.0f - t) * t;

   return vec4(r, g, b, 1.0);
}

void main()
{
   vec2 z, c;
   c.x = screen_ratio * (gl_FragCoord.x / screen_size.x - 0.5);
   c.y = (gl_FragCoord.y / screen_size.y - 0.5);

   c.x /= zoom;
   c.y /= zoom;

   c.x += center.x;
   c.y += center.y;

   z.x = mode*c.x;
   z.y = mode*c.y;

   c.x = (1-mode)*c.x + mode*0.6f;
   c.y = (1-mode)*c.y + mode*0.55f;

   int i;
   for (i = 0; i < itr; i++)
   {
       float x = z.x;
       float y = z.y;
       for (int p = 1; p < pwr; p++)
       {
           float nx = x * z.x - y * z.y;
           float ny = x * z.y + y * z.x;
           x = nx;
           y = ny;
       }

       x += c.x;
       y += c.y;

       if ((x*x + y*y) > 4.0) break;
       z.x = x;
       z.y = y;
   }

   float t = float(i) / float(itr);

   if (texture(name, TexCoord).x > 0.1f) {
       FragColor = texture(name, TexCoord);
   } else {
       FragColor = map_to_color(t);
   }
}