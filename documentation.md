The function apply_gaussian_blur is a public method of the Rotatebmp class that applies a Gaussian blur filter to the current BMP image stored in memory. This filter is used to reduce noise and smooth the image by convolving each pixel with a predefined Gaussian kernel. The function does not take any parameters and modifies the internal image buffer directly.

If the Gaussian kernel has not been created before the function call, the method create_kernel() is invoked to generate it. A temporary output buffer ans is allocated to store the resulting blurred image data. The function iterates over each pixel of the image, applying the convolution by summing the weighted color values of neighboring pixels. The weights are determined by the Gaussian kernel. For each pixel, the red, green, and blue channels are processed separately.

The loop over the rows of the image is parallelized using OpenMP with #pragma omp parallel for, allowing multiple rows to be processed concurrently. This parallelization is safe because each thread writes to a unique portion of the output buffer, and the input buffer is read-only during the process.

After processing, the original image buffer curbiTable is deallocated, and the newly computed blurred image stored in ans is assigned as the new buffer. The function ensures memory safety by releasing used resources and avoids writing outside image bounds by checking pixel indices. The function guarantees that all color values remain within the 0–255 range using clamping.

This method is designed for efficient execution on multi-core processors and improves performance for large images through parallelization while maintaining correctness and image integrity.
