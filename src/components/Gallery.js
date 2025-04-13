import React from "react";
import styled from "styled-components";
import { motion } from "framer-motion";
import { useInView } from "react-intersection-observer";

const GallerySection = styled.section`
  padding: 120px 0;
  background: linear-gradient(
    135deg,
    ${({ theme }) => theme.colors.lightBg} 0%,
    ${({ theme }) => theme.colors.white} 100%
  );
`;

const SectionTitle = styled(motion.h2)`
  font-size: 3rem;
  text-align: center;
  margin-bottom: 80px;
  font-weight: 700;
  color: ${({ theme }) => theme.colors.text};
  position: relative;

  &::after {
    content: "";
    position: absolute;
    bottom: -15px;
    left: 50%;
    transform: translateX(-50%);
    width: 80px;
    height: 4px;
    background: ${({ theme }) => theme.colors.accent};
    border-radius: 2px;
  }
`;

const GalleryGrid = styled.div`
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
  gap: 30px;
  max-width: 1200px;
  margin: 0 auto;
  padding: 0 20px;
`;

const ImageContainer = styled(motion.div)`
  position: relative;
  border-radius: 15px;
  overflow: hidden;
  aspect-ratio: 4/3;
  cursor: pointer;
  box-shadow: 0 10px 30px rgba(0, 0, 0, 0.1);
  transition: ${({ theme }) => theme.transition};

  &:hover {
    transform: translateY(-10px);
    box-shadow: 0 20px 40px rgba(0, 0, 0, 0.2);
  }
`;

const Image = styled.img`
  width: 100%;
  height: 100%;
  object-fit: cover;
  transition: transform 0.5s ease;

  ${ImageContainer}:hover & {
    transform: scale(1.1);
  }
`;

const ImageOverlay = styled.div`
  position: absolute;
  bottom: 0;
  left: 0;
  right: 0;
  background: linear-gradient(to top, rgba(0, 0, 0, 0.8), transparent);
  padding: 20px;
  transform: translateY(100%);
  transition: transform 0.3s ease;

  ${ImageContainer}:hover & {
    transform: translateY(0);
  }
`;

const ImageTitle = styled.h3`
  color: white;
  font-size: 1.2rem;
  margin-bottom: 8px;
`;

const ImageDescription = styled.p`
  color: rgba(255, 255, 255, 0.9);
  font-size: 0.9rem;
  line-height: 1.4;
`;

const Gallery = () => {
  const [ref, inView] = useInView({
    triggerOnce: true,
    threshold: 0.1,
  });

  const images = [
    {
      src: "/gallery/IISC.jpg",
      title: "IISC Open Day 2025",
    },
    {
      src: "/gallery/Induction.jpg",
      title: "Induction Ceremony 2023",
    },
    {
      src: "/gallery/Azure Training.jpg",
      title: "AZ-900 Training 2024",
    },
    {
      src: "/gallery/OS Activity.jpg",
      title: "OS Activity 2024",
    },
    {
      src: "/gallery/NCMC.jpg",
      title: "NCMC Activity 2024",
    },
    {
      src: "/gallery/Physics Seminar.jpg",
      title: "Physics Seminar 2023",
    },
    // Add more images here with their titles and descriptions
  ];

  return (
    <GallerySection id="gallery">
      <SectionTitle
        ref={ref}
        initial={{ opacity: 0, y: 20 }}
        animate={inView ? { opacity: 1, y: 0 } : {}}
        transition={{ duration: 0.5 }}
      >
        Gallery
      </SectionTitle>
      <GalleryGrid>
        {images.map((image, index) => (
          <ImageContainer
            key={index}
            initial={{ opacity: 0, y: 20 }}
            animate={inView ? { opacity: 1, y: 0 } : {}}
            transition={{ duration: 0.5, delay: index * 0.1 }}
          >
            <Image
              src={process.env.PUBLIC_URL + image.src}
              alt={image.title}
              onError={(e) => {
                console.error("Image failed to load:", e);
                e.target.style.border = "2px solid red";
              }}
            />
            <ImageOverlay>
              <ImageTitle>{image.title}</ImageTitle>
              <ImageDescription>{image.description}</ImageDescription>
            </ImageOverlay>
          </ImageContainer>
        ))}
      </GalleryGrid>
    </GallerySection>
  );
};

export default Gallery;
