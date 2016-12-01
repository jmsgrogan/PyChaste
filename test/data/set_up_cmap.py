from matplotlib import cm

out_colors = "double accent_colors[256][3] = \n {"

for idx in range(255):
    out_colors = out_colors + "{" + str(cm.Accent(idx)[0]) + "," + str(cm.Accent(idx)[1]) + "," + str(cm.Accent(idx)[2]) + "}, \n"
    
out_colors += "};"
print out_colors