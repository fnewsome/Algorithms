FloodFill(Pixel p, Color curr, Color new)
{
    if Color(p) != curr then return
        Q.Add(p); // Q is a queue that stores pixels
        while Q is not empty do
        {
            p = Q.getFirst();
            if Color(p) == curr then set color(p) = new;
            Q.Add(p.rightPixel());
            Q.Add(p.leftPixel());
            Q.Add(p.topPixel());
            Q.Add(p.bottomPixel());
         }
     return;
}