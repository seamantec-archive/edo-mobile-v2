.pragma library



function pad(n, width, z) {
  z = z || '0';
  n = n + '';
  return n.length >= width ? n : new Array(width - n.length + 1).join(z) + n;
}

function dp(value, contentScaleFactor){
    return value * contentScaleFactor;
}

