# Image Similarity Detection in C

This project implements **image similarity detection** in C using **cosine similarity** and pixel-level comparison.
It demonstrates how to load, process, and compare images using the lightweight [stb_image](https://github.com/nothings/stb) and [stb_image_write](https://github.com/nothings/stb) libraries.

---

## ✨ Features

* Load `.jpg` or `.png` images.
* Compare two images using **cosine similarity** between their pixel vectors.
* Threshold-based background replacement (basic).
* Save the processed image as a new file.

---

## 📂 Project Structure

```
├── Headers/
│   ├── stb_image.h
│   ├── stb_image_write.h
├── images/
│   ├── background.jpg
│   ├── foreground.jpg
│   ├── new_background.jpg
│   └── result.jpg
├── main.c
└── README.md
```

---

## ⚙️ How to Build & Run

### 1. Clone the repository

```bash
git clone https://github.com/<your-username>/<repo-name>.git
cd <repo-name>
```

### 2. Compile

```bash
gcc main.c -o image_detect -lm
```

### 3. Run

```bash
./image_detect
```

---

## 🖼️ Example (Background Replacement)

Input:

* `background.jpg`
* `foreground.jpg`
* `new_background.jpg`

Output:

* `result.jpg` (foreground blended into new background)

---

## 🔎 Example (Cosine Similarity)

You can add a cosine similarity function like this:

```c
double cosine_similarity(unsigned char *img1, unsigned char *img2, int size) {
    double dot = 0.0, norm1 = 0.0, norm2 = 0.0;
    for (int i = 0; i < size; i++) {
        dot   += img1[i] * img2[i];
        norm1 += img1[i] * img1[i];
        norm2 += img2[i] * img2[i];
    }
    return dot / (sqrt(norm1) * sqrt(norm2) + 1e-10);
}
```

Usage:

```c
int size = width * height * channel;
double sim = cosine_similarity(image1, image2, size);
printf("Cosine similarity = %f\n", sim);
```

---

## 📚 Dependencies

* [stb_image.h](https://github.com/nothings/stb/blob/master/stb_image.h)
* [stb_image_write.h](https://github.com/nothings/stb/blob/master/stb_image_write.h)

---

## 🚀 Future Work

* Improve **cosine similarity**-based detection for better accuracy.
* Add CLI arguments for input/output paths.
* Batch process multiple images.

---

## 📝 License

This project is released under the MIT License.
