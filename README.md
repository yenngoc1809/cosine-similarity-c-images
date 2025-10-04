# Background Removal in C

This project implements a simple **background removal** program in C.
It compares two images pixel by pixel and replaces the background with a new one when the difference between pixels exceeds a threshold.
The program uses the lightweight [stb_image](https://github.com/nothings/stb) and [stb_image_write](https://github.com/nothings/stb) libraries for loading and saving images.

---

## ✨ Features

* Load `.jpg` images using `stb_image`.
* Compare **foreground** and **background** images pixel by pixel.
* Replace background pixels with a **new background image** if they differ significantly.
* Save the result as a new image.

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
gcc main.c -o background_removal -lm
```

### 3. Run

```bash
./background_removal
```

---

## 🖼️ Example

Input:

* `background.jpg`
* `foreground.jpg`
* `new_background.jpg`

Output:

* `result.jpg` → foreground blended into the new background

---

## 📚 Dependencies

* [stb_image.h](https://github.com/nothings/stb/blob/master/stb_image.h)
* [stb_image_write.h](https://github.com/nothings/stb/blob/master/stb_image_write.h)

---

## 🚀 Future Work

* Add support for PNG and other formats.
* Allow custom threshold values.
* Implement similarity metrics (e.g., cosine similarity) for more advanced comparisons.

---

## 📝 License

This project is released under the MIT License.
