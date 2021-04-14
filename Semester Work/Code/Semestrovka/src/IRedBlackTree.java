public interface IRedBlackTree <T extends Comparable<T>>{
    void add(T value);
    boolean remove(T value);
    boolean contains(T value);
}
