import React from "react";
import styled from "styled-components";
import { motion } from "framer-motion";
import { useInView } from "react-intersection-observer";

const GallerySection = styled.section`
  padding: 120px 0;
  background-color: ${({ theme }) => theme.colors.lightBg};

  @media (max-width: ${({ theme }) => theme.breakpoints.tablet}) {
    padding: 80px 0;
  }

  @media (max-width: ${({ theme }) => theme.breakpoints.mobile}) {
    padding: 60px 0;
  }
`;

const SectionTitle = styled(motion.h2)`
  font-size: 3rem;
  text-align: center;
  margin-bottom: 80px;
  font-weight: 700;
  color: ${({ theme }) => theme.colors.text};

  @media (max-width: ${({ theme }) => theme.breakpoints.tablet}) {
    font-size: 2.5rem;
    margin-bottom: 60px;
  }

  @media (max-width: ${({ theme }) => theme.breakpoints.mobile}) {
    font-size: 2rem;
    margin-bottom: 40px;
  }
`;

const GalleryGrid = styled.div`
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
  gap: 30px;
  max-width: 1200px;
  margin: 0 auto;
  padding: 0 20px;

  @media (max-width: ${({ theme }) => theme.breakpoints.tablet}) {
    grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
    gap: 25px;
    padding: 0 15px;
  }

  @media (max-width: ${({ theme }) => theme.breakpoints.mobile}) {
    grid-template-columns: 1fr;
    gap: 20px;
    padding: 0 10px;
  }
`;

const GalleryItem = styled(motion.div)`
  position: relative;
  border-radius: 12px;
  overflow: hidden;
  cursor: pointer;
  aspect-ratio: 16/9;
  box-shadow: 0 10px 30px rgba(0, 0, 0, 0.1);

  @media (max-width: ${({ theme }) => theme.breakpoints.mobile}) {
    border-radius: 8px;
  }

  &:hover {
    .overlay {
      opacity: 1;
      transform: translateY(0);
    }
  }
`;

const GalleryImage = styled.img`
  width: 100%;
  height: 100%;
  object-fit: cover;
  transition: ${({ theme }) => theme.transition};
`;

const Overlay = styled.div`
  position: absolute;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
  background: rgba(0, 0, 0, 0.7);
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  padding: 20px;
  opacity: 0;
  transform: translateY(20px);
  transition: ${({ theme }) => theme.transition};

  @media (max-width: ${({ theme }) => theme.breakpoints.mobile}) {
    padding: 15px;
  }
`;

const ImageTitle = styled.h3`
  color: white;
  font-size: 1.5rem;
  margin-bottom: 10px;
  text-align: center;

  @media (max-width: ${({ theme }) => theme.breakpoints.tablet}) {
    font-size: 1.3rem;
    margin-bottom: 8px;
  }

  @media (max-width: ${({ theme }) => theme.breakpoints.mobile}) {
    font-size: 1.2rem;
    margin-bottom: 6px;
  }
`;

const ImageDescription = styled.p`
  color: rgba(255, 255, 255, 0.9);
  font-size: 1rem;
  text-align: center;
  line-height: 1.5;

  @media (max-width: ${({ theme }) => theme.breakpoints.tablet}) {
    font-size: 0.95rem;
    line-height: 1.4;
  }

  @media (max-width: ${({ theme }) => theme.breakpoints.mobile}) {
    font-size: 0.9rem;
    line-height: 1.3;
  }
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
          <GalleryItem
            key={index}
            initial={{ opacity: 0, y: 20 }}
            animate={inView ? { opacity: 1, y: 0 } : {}}
            transition={{ duration: 0.5, delay: index * 0.1 }}
          >
            <GalleryImage
              src={process.env.PUBLIC_URL + image.src}
              alt={image.title}
              onError={(e) => {
                console.error("Image failed to load:", e);
                e.target.style.border = "2px solid red";
              }}
            />
            <Overlay>
              <ImageTitle>{image.title}</ImageTitle>
              <ImageDescription>{image.description}</ImageDescription>
            </Overlay>
          </GalleryItem>
        ))}
      </GalleryGrid>
    </GallerySection>
  );
};

export default Gallery;
